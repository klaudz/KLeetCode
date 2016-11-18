//
//  defines.h
//  kLeetCode
//
//  Created by klaudz on 18/11/2016.
//  Copyright © 2016 klaudz. All rights reserved.
//

#ifndef defines_h
#define defines_h

#include <stdio.h>
#include <stdlib.h>

#if !defined(k_extern)
#  if defined(__cplusplus)
#    define k_extern extern "C"
#  else
#    define k_extern extern
#  endif
#endif

#endif /* defines_h */
