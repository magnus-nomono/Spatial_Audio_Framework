/*
 * Copyright 2016-2018 Leo McCormack
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
 * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
 * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
 * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
 * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

/**
 * @file saf_utility_sensorarray_presets.c
 * @ingroup Utilities
 * @brief A collection of microphone array sensor directions
 * 
 * @author Leo McCormack
 * @date 11.07.2016
 * @license ISC
 */

#include "saf_utility_sensorarray_presets.h"

/* ========================================================================== */
/*                             First Order Arrays                             */
/* ========================================================================== */

const float __Aalto_Hydrophone_coords_rad[4][2] =
{ { -2.35619449019235f,    -0.615490213662568f},
  { 0.785398163397448f,    -0.615479708670387f},
  { -0.785398163397448f,    0.615479708670387f},
  { 2.35619449019235f,    0.615479708670387f} };

const float __Sennheiser_Ambeo_coords_rad[4][2] =
{ { 0.785398163397448f,    0.615472907423280f},
  { -0.785398163397448f,    -0.615472907423280f},
  { 2.35619449019235f,    -0.615472907423280f},
  { -2.35619449019235f,    0.615472907423280f}};

const float __Core_Sound_TetraMic_coords_rad[4][2] =
{ { 0.785398163397448f,    0.615472907423280f},
  { -0.785398163397448f,    -0.615472907423280f},
  { 2.35619449019235f,    -0.615472907423280f},
  { -2.35619449019235f,    0.615472907423280f}};

const float __Zoom_H3VR_coords_rad[4][2] =
{ { 0.785398163397448f,    0.615472907423280f},
    { -0.785398163397448f,    -0.615472907423280f},
    { 2.35619449019235f,    -0.615472907423280f},
    { -2.35619449019235f,    0.615472907423280f}};

const float __Sound_field_SPS200_coords_rad[4][2] =
{ { 0.785398163397448f,    0.615472907423280f},
  { -0.785398163397448f,    -0.615472907423280f},
  { 2.35619449019235f,    -0.615472907423280f},
  { -2.35619449019235f,    0.615472907423280f}};


/* ========================================================================== */
/*                             Third Order Arrays                             */
/* ========================================================================== */

const float __Zylia1D_coords_rad[19][2] =
{ { 0.0f,    1.57079632679490f},
  { 0.00305809444245928f,    0.840254037451382f},
  { 2.09600986753364f,    0.840126252832125f},
  { -2.09336058192593f,    0.840886905122138f},
  { -1.43409959239697f,    0.338967177556435f},
  { -0.656487391713457f,    0.339152933310760f},
  { 0.661232814211584f,    0.338858655681573f},
  { 1.43624308141539f,    0.339058915910358f},
  { 2.75545932621978f,    0.339167630604397f},
  { -2.75063229463181f,    0.339281599533891f},
  { -2.48035983937821f,    -0.338858655681573f},
  { -1.70534957217440f,    -0.339058915910358f},
  { -0.386133327370014f,    -0.339167630604397f},
  { 0.390960358957982f,    -0.339281599533891f},
  { 1.70749306119282f,    -0.338967177556435f},
  { 2.48510526187634f,    -0.339152933310760f},
  { -3.13853455914733f,    -0.840254037451382f},
  { -1.04558278605616f,    -0.840126252832125f},
  { 1.04823207166387f,    -0.840886905122138f}};


/* ========================================================================== */
/*                             Fourth Order Arrays                            */
/* ========================================================================== */

const float __Eigenmike32_coords_rad[32][2] =
{ { 0.0f,    0.366519142918809f},
  { 0.558505360638186f,    0.0f},
  { 0.0f,    -0.366519142918809f},
  { 5.72467994654140f,    0.0f},
  { 0.0f,    1.01229096615671f},
  { 0.785398163397448f,    0.610865238198015f},
  { 1.20427718387609f,    0.0f},
  { 0.785398163397448f,    -0.610865238198015f},
  { 0.0f,    -1.01229096615671f},
  { 5.49778714378214f,    -0.610865238198015f},
  { 5.07890812330350f,    0.0f},
  { 5.49778714378214f,    0.610865238198015f},
  { 1.58824961931484f,    1.20427718387609f},
  { 1.57079632679490f,    0.558505360638186f},
  { 1.57079632679490f,    -0.541052068118242f},
  { 1.55334303427495f,    -1.20427718387609f},
  { 3.14159265358979f,    0.366519142918809f},
  { 3.70009801422798f,    0.0f},
  { 3.14159265358979f,    -0.366519142918809f},
  { 2.58308729295161f,    0.0f},
  { 3.14159265358979f,    1.01229096615671f},
  { 3.92699081698724f,    0.610865238198015f},
  { 4.34586983746588f,    0.0f},
  { 3.92699081698724f,    -0.610865238198015f},
  { 3.14159265358979f,    -1.01229096615671f},
  { 2.35619449019235f,    -0.610865238198015f},
  { 1.93731546971371f,    0.0f},
  { 2.35619449019235f,    0.610865238198015f},
  { 4.69493568786475f,    1.20427718387609f},
  { 4.71238898038469f,    0.558505360638186f},
  { 4.71238898038469f,    -0.55850536063818f},
  { 4.72984227290463f,    -1.20427718387609f} };


/* ========================================================================== */
/*                             Sixth Order Arrays                             */
/* ========================================================================== */

const float __DTU_mic_coords_rad[52][2] =
{ { 0.0f,1.40194351305251f},
  { -3.14159265358979f,    1.40194351305251f},
  { 0.523598775598299f,    0.964876234040517f},
  { 1.57079632679490f,    0.964876234040517f},
  { 2.61799387799149f,    0.964876234040517f},
  { -2.61799387799150f,    0.964876234040517f},
  { -1.57079632679490f,    0.964876234040517f},
  { -0.523598775598299f,    0.964876234040517f},
  { 0.628318530717959f,    0.502232586957315f},
  { 1.25663706143592f,    0.502232586957315f},
  { 1.88495559215388f,    0.502232586957315f},
  { 2.51327412287183f,    0.502232586957315f},
  { -3.14159265358979f,    0.502232586957315f},
  { -2.51327412287183f,    0.502232586957315f},
  { -1.88495559215388f,    0.502232586957315f},
  { -1.25663706143592f,    0.502232586957315f},
  { -0.628318530717959f,    0.502232586957315f},
  { 0.0f,    0.502232586957315f},
  { 0.589048622548086f,    0.0f},
  { 0.981747704246811f,    0.0f},
  { 1.37444678594553f,    0.0f},
  { 1.76714586764426f,    0.0f},
  { 2.15984494934298f,    0.0f},
  { 2.55254403104171f,    0.0f},
  { 2.94524311274043f,    0.0f},
  { -2.94524311274043f,    0.0f},
  { -2.55254403104171f,    0.0f},
  { -2.15984494934298f,    0.0f},
  { -1.76714586764426f,    0.0f},
  { -1.37444678594553f,    0.0f},
  { -0.981747704246811f,    0.0f},
  { -0.589048622548086f,    0.0f},
  { -0.196349540849362f,    0.0f},
  { 0.196349540849362f,    0.0f},
  { 0.314159265358979f,    -0.502232586957315f},
  { 0.942477796076938f,    -0.502232586957315f},
  { 1.57079632679490f,    -0.502232586957315f},
  { 2.19911485751286f,    -0.502232586957315f},
  { 2.82743338823081f,    -0.502232586957315f},
  { -2.82743338823081f,    -0.502232586957315f},
  { -2.19911485751286f,    -0.502232586957315f},
  { -1.57079632679490f,    -0.502232586957315f},
  { -0.942477796076938f,    -0.502232586957315f},
  { -0.314159265358979f,    -0.502232586957315f},
  { 0.0f,    -0.964876234040517f},
  { 1.04719755119660f,    -0.964876234040517f},
  { 2.09439510239320f,    -0.964876234040517f},
  { 3.14159265358979f,    -0.964876234040517f},
  { -2.09439510239320f,    -0.964876234040517f},
  { -1.04719755119660f,    -0.964876234040517f},
  { -1.57079632679490f,    -1.40194351305251f},
  { 1.57079632679490f,    -1.40194351305251f}};


/* ========================================================================== */
/*                               Default Arrays                               */
/* ========================================================================== */

const float __default_SENSORcoords64_rad[64][2] =
{ { 0.0f,     1.57079632679490f},
  { 2.39996322972865f,     1.31814860051033f},
  { -1.48325884772228f,     1.21253510828228f},
  { 0.916704382006374f,     1.13082037200398f},
  { -2.96651769544456f,     1.06135247798300f},
  { -0.566554465715905f,     0.999627828229359f},
  { 1.83340876401275f,     0.943340553871706f},
  { -2.04981331343819f,     0.891122507886653f},
  { 0.350149916290469f,     0.842082876051491f},
  { 2.75011314601912f,     0.795602953484535f},
  { -1.13310893143181f,     0.751231999126636f},
  { 1.26685429829684f,     0.708629271562384f},
  { -2.61636777915409f,     0.667529444635833f},
  { -0.216404549425435f,     0.627720817657913f},
  { 2.18355868030321f,     0.589030970216274f},
  { -1.69966339714772f,     0.551316969131883f},
  { 0.700299832580937f,     0.514458475561187f},
  { 3.10026306230959f,     0.478352764649258f},
  { -0.782959015141339f,     0.442911044073639f},
  { 1.61700421458731f,     0.408055677301279f},
  { -2.26621786286362f,     0.373718050942914f},
  { 0.133745366865034f,     0.339836909454122f},
  { 2.53370859659368f,     0.306357034556919f},
  { -1.34951348085725f,     0.273228182540638f},
  { 1.05044974887141f,     0.240404216769259f},
  { -2.83277232857953f,     0.207842389353347f},
  { -0.432809098850870f,     0.175502737575723f},
  { 1.96715413087779f,     0.143347568905365f},
  { -1.91606794657316f,     0.111341014340964f},
  { 0.483895283155495f,     0.0794486340851373f},
  { 2.88385851288415f,     0.0476370626244032f},
  { -0.999363564566781f,     0.0158736824899558f},
  { 1.40059966516187f,     -0.0158736824899556f},
  { -2.48262241228906f,     -0.0476370626244031f},
  { -0.0826591825604016f,     -0.0794486340851372f},
  { 2.31730404716825f,     -0.111341014340964f},
  { -1.56591803028268f,     -0.143347568905365f},
  { 0.834045199445964f,     -0.175502737575723f},
  { -3.04917687800497f,     -0.207842389353347f},
  { -0.649213648276312f,     -0.240404216769259f},
  { 1.75074958145234f,     -0.273228182540638f},
  { -2.13247249599859f,     -0.306357034556919f},
  { 0.267490733730067f,     -0.339836909454122f},
  { 2.66745396345872f,     -0.373718050942914f},
  { -1.21576811399222f,     -0.408055677301278f},
  { 1.18419511573643f,     -0.442911044073639f},
  { -2.69902696171450f,     -0.478352764649258f},
  { -0.299063731985844f,     -0.514458475561187f},
  { 2.10089949774281f,     -0.551316969131883f},
  { -1.78232257970812f,     -0.589030970216274f},
  { 0.617640650020536f,     -0.627720817657913f},
  { 3.01760387974919f,     -0.667529444635833f},
  { -0.865618197701740f,     -0.708629271562384f},
  { 1.53434503202690f,     -0.751231999126636f},
  { -2.34887704542402f,     -0.795602953484536f},
  { 0.0510861843046390f,     -0.842082876051491f},
  { 2.45104941403327f,     -0.891122507886652f},
  { -1.43217266341767f,     -0.943340553871706f},
  { 0.967790566310990f,     -0.999627828229359f},
  { -2.91543151113994f,     -1.06135247798300f},
  { -0.515468281411286f,     -1.13082037200398f},
  { 1.88449494831737f,     -1.21253510828228f},
  { -1.99872712913356f,     -1.31814860051033f},
  { 0.401236100595093f,     -1.57079632679490f} };

const int __Aalto_Hydrophone_maxOrder = 1;
const int __Sennheiser_Ambeo_maxOrder = 1;
const int __Core_Sound_TetraMic_maxOrder = 1;
const int __Sound_field_SPS200_maxOrder = 1;
const int __Zylia_maxOrder = 3;
const int __Eigenmike32_maxOrder = 4;
const int __DTU_mic_maxOrder = 6;

const float __Zylia_freqRange[4] =
{ 420.0f, 1200.0f, 3500.0f, 3700.0f};

const float __Eigenmike32_freqRange[6] =
{ 460.0f, 1200.0f, 2200.0f, 6500.0f, 7500.0f, 8300.0f};

const float __DTU_mic_freqRange[10] =
{ 350.0f, 950.0f, 1700.0f, 2600.0f, 3500.0f, 5800.0f, 6600.0f, 7200.0f, 7700.0f, 8300.0f};


