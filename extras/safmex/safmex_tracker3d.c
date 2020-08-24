/*
 * This file is part of the saf_tracker module.
 * Copyright (c) 2020 - Leo McCormack
 *
 * The saf_tracker module is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * The saf_tracker module is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * See <http://www.gnu.org/licenses/> for a copy of the GNU General Public
 * License.
 */
 
#include "safmex.h"

/* ===================================================================== */
/*                                Config                                 */
/* ===================================================================== */

#define NUM_INPUT_ARGS_FWD ( 1 )
#define NUM_OUTPUT_ARGS_FWD ( 1 )
#define NUM_INPUT_ARGS_BKWD ( 1 )
#define NUM_OUTPUT_ARGS_BKWD ( 1 )
const MEX_DATA_TYPES inputDataTypes_fwd[NUM_INPUT_ARGS_FWD] = {
    SM_DOUBLE_REAL_1D_OR_2D      
}; 
const MEX_DATA_TYPES inputDataTypes_bkwd[NUM_INPUT_ARGS_BKWD] = {
    SM_DOUBLE_COMPLEX_3D      
}; 
const MEX_DATA_TYPES outputDataTypes_fwd[NUM_OUTPUT_ARGS_FWD] = {
    SM_DOUBLE_COMPLEX_3D 
}; 
const MEX_DATA_TYPES outputDataTypes_bkwd[NUM_OUTPUT_ARGS_BKWD] = {
    SM_DOUBLE_REAL_1D_OR_2D      
}; 


/* ===================================================================== */
/*                                 Vars                                  */
/* ===================================================================== */

/* user arguments */
tracker3d_config tpars;

/* internal parameters */
void* hT3d = NULL;                /* tracker3d handle */ 
int ifield, nfields;
 
/* ===================================================================== */
/*                              MEX Wrapper                              */
/* ===================================================================== */

void mexFunction
(
    int nlhs,             /* Number of input argments */
    mxArray *plhs[],      /* Pointers for input arguments */
    int nrhs,             /* Number of output argments */
    const mxArray *prhs[] /* Pointers for output arguments */
)
{  
    /* mex variables */
    int nDims;
    int *pDims = NULL;
     
    /* DESTROY */
    if(nrhs == 0){
        if(hT3d!=NULL){
            mexPrintf("Destroying tracker3d.\n");
            tracker3d_destroy(&hT3d); 
            hT3d = NULL;
        } 
        else
            mexPrintf("tracker3d is already dead!\n"); 
    }
    
    /* CREATE */
    else if(nrhs==1){
        if(hT3d!=NULL)
            mexErrMsgIdAndTxt("MyToolbox:inputError","tracker3d is already initialised! First destroy it if you want to change its configuration.");

        /* Check if prhs[1] is a struct */
        if(!mxIsStruct(prhs[0]))
            mexErrMsgIdAndTxt("MyToolbox:inputError","Input must be a struct"); 

        /* get the values from the struct */
        const mxArray  *mxTmp; 
        double         *tmp;

        /* tpars.Np */
        mxTmp = mxGetField(prhs[0],0,"Np"); 
        if(mxTmp==NULL)
            mexErrMsgIdAndTxt("MyToolbox:inputError","'Np' is not defined"); 
        if (mxIsComplex(mxTmp) || mxGetNumberOfElements(mxTmp)!=1 || (int)mxGetScalar(mxTmp)<1 || (int)mxGetScalar(mxTmp)>100)
            mexErrMsgIdAndTxt("MyToolbox:inputError","'Np' must be an integer between 1 and 100");
        tpars.Np = (int)mxGetScalar(mxTmp);

        /* tpars.maxNactiveTargets */
        mxTmp = mxGetField(prhs[0],0,"maxNactiveTargets"); 
        if(mxTmp==NULL)
            mexErrMsgIdAndTxt("MyToolbox:inputError","'maxNactiveTargets' is not defined"); 
        if (mxIsComplex(mxTmp) || mxGetNumberOfElements(mxTmp)!=1 || (int)mxGetScalar(mxTmp)<1 || (int)mxGetScalar(mxTmp)>100)
            mexErrMsgIdAndTxt("MyToolbox:inputError","'maxNactiveTargets' must be an integer between 1 and 100");
        tpars.maxNactiveTargets = (int)mxGetScalar(mxTmp);

        /* tpars.noiseLikelihood */
        mxTmp = mxGetField(prhs[0],0,"noiseLikelihood"); 
        if(mxTmp==NULL)
            mexErrMsgIdAndTxt("MyToolbox:inputError","'noiseLikelihood' is not defined"); 
        if (mxIsComplex(mxTmp) || mxGetNumberOfElements(mxTmp)!=1 || mxGetScalar(mxTmp)<0 || mxGetScalar(mxTmp)>1)
            mexErrMsgIdAndTxt("MyToolbox:inputError","'noiseLikelihood' must be a scalar between 0 and 1");
        tpars.noiseLikelihood = mxGetScalar(mxTmp);

        /* tpars.measNoiseSD */
        mxTmp = mxGetField(prhs[0],0,"measNoiseSD"); 
        if(mxTmp==NULL)
            mexErrMsgIdAndTxt("MyToolbox:inputError","'measNoiseSD' is not defined"); 
        if (mxIsComplex(mxTmp) || mxGetNumberOfElements(mxTmp)!=1 || mxGetScalar(mxTmp)<0)
            mexErrMsgIdAndTxt("MyToolbox:inputError","'measNoiseSD' must be a scalar");
        tpars.measNoiseSD = mxGetScalar(mxTmp);

        /* tpars.noiseSpecDen */
        mxTmp = mxGetField(prhs[0],0,"noiseSpecDen"); 
        if(mxTmp==NULL)
            mexErrMsgIdAndTxt("MyToolbox:inputError","'noiseSpecDen' is not defined"); 
        if (mxIsComplex(mxTmp) || mxGetNumberOfElements(mxTmp)!=1 || mxGetScalar(mxTmp)<0)
            mexErrMsgIdAndTxt("MyToolbox:inputError","'noiseSpecDen' must be a scalar");
        tpars.noiseSpecDen = mxGetScalar(mxTmp);

        /* tpars.ALLOW_MULTI_DEATH */
        mxTmp = mxGetField(prhs[0],0,"ALLOW_MULTI_DEATH"); 
        if(mxTmp==NULL)
            mexErrMsgIdAndTxt("MyToolbox:inputError","'ALLOW_MULTI_DEATH' is not defined"); 
        if (mxIsComplex(mxTmp) || mxGetNumberOfElements(mxTmp)!=1 || (int)mxGetScalar(mxTmp)<0 || (int)mxGetScalar(mxTmp)>1)
            mexErrMsgIdAndTxt("MyToolbox:inputError","'ALLOW_MULTI_DEATH' must be 0 or 1");
        tpars.ALLOW_MULTI_DEATH = (int)mxGetScalar(mxTmp);

        /* tpars.init_birth */
        mxTmp = mxGetField(prhs[0],0,"init_birth"); 
        if(mxTmp==NULL)
            mexErrMsgIdAndTxt("MyToolbox:inputError","'init_birth' is not defined"); 
        if (mxIsComplex(mxTmp) || mxGetNumberOfElements(mxTmp)!=1 || mxGetScalar(mxTmp)<0 || mxGetScalar(mxTmp)>1)
            mexErrMsgIdAndTxt("MyToolbox:inputError","'init_birth' must be a scalar between 0 and 1");
        tpars.init_birth = mxGetScalar(mxTmp);

        /* tpars.alpha_death */
        mxTmp = mxGetField(prhs[0],0,"alpha_death"); 
        if(mxTmp==NULL)
            mexErrMsgIdAndTxt("MyToolbox:inputError","'alpha_death' is not defined"); 
        if (mxIsComplex(mxTmp) || mxGetNumberOfElements(mxTmp)!=1 || mxGetScalar(mxTmp)<0 )
            mexErrMsgIdAndTxt("MyToolbox:inputError","'alpha_death' must be a scalar");
        tpars.alpha_death = mxGetScalar(mxTmp);

        /* tpars.beta_death */
        mxTmp = mxGetField(prhs[0],0,"beta_death"); 
        if(mxTmp==NULL)
            mexErrMsgIdAndTxt("MyToolbox:inputError","'beta_death' is not defined"); 
        if (mxIsComplex(mxTmp) || mxGetNumberOfElements(mxTmp)!=1 || mxGetScalar(mxTmp)<0 )
            mexErrMsgIdAndTxt("MyToolbox:inputError","'beta_death' must be a scalar");
        tpars.beta_death = mxGetScalar(mxTmp);

        /* tpars.dt */
        mxTmp = mxGetField(prhs[0],0,"dt"); 
        if(mxTmp==NULL)
            mexErrMsgIdAndTxt("MyToolbox:inputError","'dt' is not defined"); 
        if (mxIsComplex(mxTmp) || mxGetNumberOfElements(mxTmp)!=1 || mxGetScalar(mxTmp)<0 )
            mexErrMsgIdAndTxt("MyToolbox:inputError","'dt' must be a scalar");
        tpars.dt = mxGetScalar(mxTmp);

        /* tpars.W_avg_coeff */
        mxTmp = mxGetField(prhs[0],0,"W_avg_coeff"); 
        if(mxTmp==NULL)
            mexErrMsgIdAndTxt("MyToolbox:inputError","'W_avg_coeff' is not defined"); 
        if (mxIsComplex(mxTmp) || mxGetNumberOfElements(mxTmp)!=1 || mxGetScalar(mxTmp)<0 || mxGetScalar(mxTmp)>1)
            mexErrMsgIdAndTxt("MyToolbox:inputError","'W_avg_coeff' must be a scalar between 0 and 1");
        tpars.W_avg_coeff = mxGetScalar(mxTmp);

        /* tpars.FORCE_KILL_TARGETS */
        mxTmp = mxGetField(prhs[0],0,"FORCE_KILL_TARGETS"); 
        if(mxTmp==NULL)
            mexErrMsgIdAndTxt("MyToolbox:inputError","'FORCE_KILL_TARGETS' is not defined"); 
        if (mxIsComplex(mxTmp) || mxGetNumberOfElements(mxTmp)!=1 || (int)mxGetScalar(mxTmp)<0 || (int)mxGetScalar(mxTmp)>1)
            mexErrMsgIdAndTxt("MyToolbox:inputError","'FORCE_KILL_TARGETS' must be 0 or 1");
        tpars.FORCE_KILL_TARGETS = (int)mxGetScalar(mxTmp);

        /* tpars.forceKillDistance */
        mxTmp = mxGetField(prhs[0],0,"forceKillDistance"); 
        if(mxTmp==NULL)
            mexErrMsgIdAndTxt("MyToolbox:inputError","'forceKillDistance' is not defined"); 
        if (mxIsComplex(mxTmp) || mxGetNumberOfElements(mxTmp)!=1 || mxGetScalar(mxTmp)<0 )
            mexErrMsgIdAndTxt("MyToolbox:inputError","'forceKillDistance' must be a scalar");
        tpars.forceKillDistance = mxGetScalar(mxTmp);

        /* tpars.M0 */
        mxTmp = mxGetField(prhs[0],0,"M0"); 
        if(mxTmp==NULL)
            mexErrMsgIdAndTxt("MyToolbox:inputError","'M0' is not defined"); 
        if (mxIsComplex(mxTmp) || mxGetNumberOfElements(mxTmp)!=6)
            mexErrMsgIdAndTxt("MyToolbox:inputError","'M0' must be a 6-element vector");
        tmp = mxGetData(mxTmp);
        for(int jj = 0; jj<6; jj++)
            tpars.M0[jj] = (float)tmp[jj]; 
        
        /* tpars.P0 */
        mxTmp = mxGetField(prhs[0],0,"P0"); 
        if(mxTmp==NULL)
            mexErrMsgIdAndTxt("MyToolbox:inputError","'P0' is not defined"); 
        if (mxIsComplex(mxTmp) || mxGetNumberOfElements(mxTmp)!=36)
            mexErrMsgIdAndTxt("MyToolbox:inputError","'P0' must be a 6-by-6 matrix (or stacked 36-element vector)");
        tmp = mxGetData(mxTmp);
        for(int jj = 0; jj<6; jj++)
            for(int kk=0; kk<6; kk++)
                tpars.P0[jj][kk] = (float)tmp[jj*6+kk]; 
 
        /* tpars.cd */
        mxTmp = mxGetField(prhs[0],0,"cd"); 
        if(mxTmp==NULL)
            mexErrMsgIdAndTxt("MyToolbox:inputError","'cd' is not defined"); 
        if (mxIsComplex(mxTmp) || mxGetNumberOfElements(mxTmp)!=1 || mxGetScalar(mxTmp)<0 )
            mexErrMsgIdAndTxt("MyToolbox:inputError","'cd' must be a scalar");
        tpars.cd = mxGetScalar(mxTmp);
     
        /* Create an instance of tracker3d */ 
        mexPrintf("Creating tracker3d.\n");
        tracker3d_create(&hT3d, tpars);  
    }
    
    /* Step */
    else if(nrhs == 1 && nlhs == 2){
        if(hT3d==NULL)
            mexErrMsgIdAndTxt("MyToolbox:inputError","safmex_tracker3d is uninitialised!");
          
        /* Find dimensionality of input */
        mwSize nDims_mx;
        const mwSize *pDims_mx;
        nDims_mx = mxGetNumberOfDimensions(prhs[0]);
        pDims_mx = mxGetDimensions(prhs[0]); 
         
        
    }
    
    /* ERROR */
    else 
        mexErrMsgIdAndTxt("MyToolbox:inputError","Unrecognised input/output configuration, refer to help instructions.");
}