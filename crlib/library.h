//
// crlib, simple class library for private needs.
// Copyright © RWSH Solutions LLC <lab@rwsh.ru>.
//
// SPDX-License-Identifier: MIT
//

#pragma once

#include <crlib/basic.h>
#include <crlib/string.h>

#if defined (CR_LINUX) || defined (CR_OSX)
#  include <dlfcn.h>
#  include <errno.h>
#  include <fcntl.h>
#  include <sys/stat.h>
#  include <unistd.h>
#endif

CR_NAMESPACE_BEGIN

// handling dynamic library loading
class SharedLibrary final : public NonCopyable {
public:
#if defined (CR_WINDOWS)
   using Handle = HMODULE;
   using Func = FARPROC;
#else
   using Handle = void *;
   using Func = void *;
#endif

private:
   Handle handle_ = nullptr;
   bool unloadable_ = true;

public:
   explicit SharedLibrary () = default;

   SharedLibrary (StringRef file) {
      if (file.empty ()) {
         return;
      }
      load (file);
   }

   ~SharedLibrary () {
      unload ();
   }

public:
   bool load (StringRef file, bool unloadable = true) noexcept {
      if (*this) {
         unload ();
      }
      unloadable_ = unloadable;

#if defined (CR_WINDOWS)
      handle_ = LoadLibraryA (file.chars ());
#else
      auto loadFlags = RTLD_NOW | RTLD_LOCAL;

#if defined (CR_LINUX) && !defined (CR_ANDROID) && !defined (__SANITIZE_ADDRESS__)
      loadFlags |= RTLD_DEEPBIND;
#endif
      handle_ = dlopen (file.chars (), loadFlags);
#endif
      return handle_ != nullptr;
   }

   bool locate (void *address) {
      unloadable_ = false;

#if defined (CR_WINDOWS)
      MEMORY_BASIC_INFORMATION mbi;

      if (!VirtualQuery (address, &mbi, sizeof (mbi))) {
         return false;
      }

      if (mbi.State != MEM_COMMIT) {
         return false;
      }
      handle_ = reinterpret_cast <Handle> (mbi.AllocationBase);
#else
      Dl_info dli;
      plat.bzero (&dli, sizeof (dli));

      if (dladdr (address, &dli)) {
         return load (dli.dli_fname, false);
      }
#endif
      return handle_ != nullptr;
   }

   void unload () noexcept {
      if (!handle_ || !unloadable_) {
         return;
      }

#if defined (CR_WINDOWS)
      FreeLibrary (static_cast <HMODULE> (handle_));
#else
      dlclose (handle_);
#endif
      handle_ = nullptr;
   }

   template <typename R> R resolve (const char *function) const {
      if (!*this) {
         return nullptr;
      }
      return SharedLibrary::getSymbol <R> (handle (), function);
   }

   Handle handle () const {
      return handle_;
   }

public:
   explicit operator bool () const {
      return handle_ != nullptr;
   }

public:
  template <typename R> static inline R CR_STDCALL getSymbol (Handle module, const char *function) {
      return reinterpret_cast <R> (
#if defined (CR_WINDOWS)
         GetProcAddress (static_cast <HMODULE> (module), function)
#else
         dlsym (module, function)
#endif
         );
   }
};

CR_NAMESPACE_END
