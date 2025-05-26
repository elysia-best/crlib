/*
 * SPDX-FileCopyrightText: 2024 Elysia <elysia@lingmo.org>
 *
 * SPDX-License-Identifier: GPL-3.0
 */

#ifndef CRLIB_SIMD_SSE2LSX_H
#define CRLIB_SIMD_SSE2LSX_H

// Include necessary LSX headers
#include <lsxintrin.h>

// Define macros to map SSE intrinsics to LSX intrinsics

// Arithmetic Operations
#define _mm_abs_epi16 __lsx_vsigncov_h
#define _mm_abs_epi32 __lsx_vsigncov_w
#define _mm_abs_epi8 __lsx_vsigncov_b
#define _mm_add_epi16 __lsx_vadd_h
#define _mm_add_epi32 __lsx_vadd_w
#define _mm_add_epi64 __lsx_vadd_d
#define _mm_add_epi8 __lsx_vadd_b
#define _mm_add_pd __lsx_vfadd_d
#define _mm_add_ps __lsx_vfadd_s
#define _mm_add_sd(x, y) (__lsx_vfadd_d(x, y), __lsx_vextrins_d(x, y, 0))
#define _mm_add_ss(x, y) (__lsx_vfadd_s(x, y), __lsx_vextrins_w(x, y, 0))
#define _mm_adds_epi16 __lsx_vsadd_h
#define _mm_adds_epi8 __lsx_vsadd_b
#define _mm_adds_epu16 __lsx_vsadd_hu
#define _mm_adds_epu8 __lsx_vsadd_bu

// Logical Operations
#define _mm_and_pd __lsx_vand_v
#define _mm_and_ps __lsx_vand_v
#define _mm_and_si128 __lsx_vand_v
#define _mm_andnot_pd __lsx_vandn_v
#define _mm_andnot_ps __lsx_vandn_v
#define _mm_andnot_si128 __lsx_vandn_v
#define _mm_or_pd __lsx_vor_v
#define _mm_or_ps __lsx_vor_v
#define _mm_or_si128 __lsx_vor_v
#define _mm_xor_pd __lsx_vxor_v
#define _mm_xor_ps __lsx_vxor_v
#define _mm_xor_si128 __lsx_vxor_v

// Comparison Operations
#define _mm_cmpeq_epi16 __lsx_vseq_h
#define _mm_cmpeq_epi32 __lsx_vseq_w
#define _mm_cmpeq_epi64 __lsx_vseq_d
#define _mm_cmpeq_epi8 __lsx_vseq_b
#define _mm_cmpeq_pd __lsx_vfcmp_ceq_d
#define _mm_cmpeq_ps __lsx_vfcmp_ceq_s
#define _mm_cmpeq_sd(x, y) (__lsx_vfcmp_ceq_d(x, y), __lsx_vextrins_d(x, y, 0))
#define _mm_cmpeq_ss(x, y) (__lsx_vfcmp_ceq_s(x, y), __lsx_vextrins_w(x, y, 0))
#define _mm_cmpgt_epi16 __lsx_vslt_h
#define _mm_cmpgt_epi32 __lsx_vslt_w
#define _mm_cmpgt_epi64 __lsx_vslt_d
#define _mm_cmpgt_epi8 __lsx_vslt_b
#define _mm_cmpgt_pd __lsx_vfcmp_clt_d
#define _mm_cmpgt_ps __lsx_vfcmp_clt_s
#define _mm_cmpgt_sd(x, y) (__lsx_vfcmp_clt_d(x, y), __lsx_vextrins_d(x, y, 0))
#define _mm_cmpgt_ss(x, y) (__lsx_vfcmp_clt_s(x, y), __lsx_vextrins_w(x, y, 0))
#define _mm_cmplt_epi16 __lsx_vslt_h
#define _mm_cmplt_epi32 __lsx_vslt_w
#define _mm_cmplt_epi8 __lsx_vslt_b
#define _mm_cmplt_pd __lsx_vfcmp_clt_d
#define _mm_cmplt_ps __lsx_vfcmp_clt_s
#define _mm_cmplt_sd(x, y) (__lsx_vfcmp_clt_d(x, y), __lsx_vextrins_d(x, y, 0))
#define _mm_cmplt_ss(x, y) (__lsx_vfcmp_clt_s(x, y), __lsx_vextrins_w(x, y, 0))

// Conversion Operations
#define _mm_cvtepi16_epi32 __lsx_vsllwil_w_h
#define _mm_cvtepi32_epi64 __lsx_vsllwil_d_w
#define _mm_cvtepi32_pd __lsx_vffintl_d_w
#define _mm_cvtepi32_ps __lsx_vffint_s_w
#define _mm_cvtepi8_epi16 __lsx_vsllwil_h_b
#define _mm_cvtepu16_epi32 __lsx_vsllwil_wu_hu
#define _mm_cvtepu32_epi64 __lsx_vsllwil_du_wu
#define _mm_cvtepu8_epi16 __lsx_vsllwil_hu_bu
#define _mm_cvtpd_epi32 __lsx_vftint_w_d
#define _mm_cvtps_epi32 __lsx_vftint_w_s

// Load/Store Operations
#define _mm_load_pd __lsx_vld
#define _mm_load_ps __lsx_vld
#define _mm_load_si128 __lsx_vld
#define _mm_loadu_pd __lsx_vld
#define _mm_loadu_ps __lsx_vld
#define _mm_loadu_si128 __lsx_vld
#define _mm_store_pd __lsx_vst
#define _mm_store_ps __lsx_vst
#define _mm_store_si128 __lsx_vst
#define _mm_storeu_pd __lsx_vst
#define _mm_storeu_ps __lsx_vst
#define _mm_storeu_si128 __lsx_vst

// Miscellaneous Operations
#define _mm_max_epi16 __lsx_vmax_h
#define _mm_max_epi32 __lsx_vmax_w
#define _mm_max_epi8 __lsx_vmax_b
#define _mm_max_pd __lsx_vfmax_d
#define _mm_max_ps __lsx_vfmax_s
#define _mm_min_epi16 __lsx_vmin_h
#define _mm_min_epi32 __lsx_vmin_w
#define _mm_min_epi8 __lsx_vmin_b
#define _mm_min_pd __lsx_vfmin_d
#define _mm_min_ps __lsx_vfmin_s
#define _mm_mul_pd __lsx_vfmul_d
#define _mm_mul_ps __lsx_vfmul_s
#define _mm_setzero_pd ((__m128d)__lsx_vldi(0))
#define _mm_setzero_ps ((__m128)__lsx_vldi(0))
#define _mm_setzero_si128 __lsx_vldi(0)

// Additional Operations (Partial Implementation)
// #define _mm_shuffle_epi32 /* Not directly mapped */
// #define _mm_shuffle_ps /* Not directly mapped */

#endif // CRLIB_SIMD_SSE2LSX_H