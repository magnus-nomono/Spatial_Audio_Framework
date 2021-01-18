/*
 * Copyright 2020 Leo McCormack
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
 * @file tvconv_internal.h
 * @brief A time-varying multi-channel convolver
 * @author Rapolas Daugintis
 * @date 18.11.2020
 */

#ifndef __TVCONV_INTERNAL_H_INCLUDED__
#define __TVCONV_INTERNAL_H_INCLUDED__

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#include "tvconv.h"
#include "saf.h"
#include "saf_externals.h" /* to also include saf dependencies (cblas etc.) */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* ========================================================================== */
/*                            Internal Parameters                             */
/* ========================================================================== */

#define MIN_FRAME_SIZE ( 512 )
#define MAX_FRAME_SIZE ( 8192 )
#define NUM_DIMENSIONS ( 3 )

/* ========================================================================== */
/*                                 Structures                                 */
/* ========================================================================== */

/**
 * Structure for a vector
 */
typedef float vectorND[NUM_DIMENSIONS];
/**
 * Main structure for tvconv.
 */
typedef struct _tvconv
{
    /* FIFO buffers */
    int FIFO_idx;
    float inFIFO[MAX_NUM_CHANNELS][MAX_FRAME_SIZE];
    float outFIFO[MAX_NUM_CHANNELS][MAX_FRAME_SIZE];

    /* Internal buffers */
    float** inputFrameTD;
    float** outputFrameTD;
    float** overlapTD;
    float** overlapTD_Last;
    float* fadeIn;
    float* fadeOut;
    
    /* internal */
    void* hMultiConv;
    int hostBlockSize;
    int hostBlockSize_clamped; /**< Clamped between MIN and #MAX_FRAME_SIZE */
    float** filters;   /**< npositionsx x (FLAT: nfilters x filter_length) */
    int nfilters; /** < number of filters per position */
    int filter_length;
    int filter_fs;
    int host_fs;
    int reInitFilters;
    vectorND* positions; /** < npositions x 3 */
    vectorND* positions_Last;
    unsigned int npositions;
    float minDimensions[NUM_DIMENSIONS];
    float maxDimensions[NUM_DIMENSIONS];
    unsigned int position_idx;
    unsigned int position_idx_Last;
    unsigned int position_idx_Last2;
    
    
    /* user parameters */
    int nChannels;
    int enablePartitionedConv;
    vectorND position;
    

} tvconv_data;

/* ========================================================================== */
/*                             Internal Functions                             */
/* ========================================================================== */

/**
 * FInds the index holding the nearest neigbour to the selected position
 */
void tvconv_findNearestNeigbour(void* const hTVCnv);


#ifdef __cplusplus
} /* extern "C" { */
#endif /* __cplusplus */

#endif /* __TVCONV_INTERNAL_H_INCLUDED__ */
