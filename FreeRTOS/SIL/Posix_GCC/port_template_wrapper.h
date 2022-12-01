
#pragma once
#ifndef _PORT_TEMPLATE_WRAPPER_
#define _PORT_TEMPLATE_WRAPPER_

#ifdef __cplusplus
extern "C" {
#endif

/// Instantiate an instance of Port<T> and return Void Pointer to it [REQUIRED]
extern void *createMyPort();

/// Accept a Void Pointer to Port<T> and delete that object [REQUIRED]
extern void deleteMyPort(void *obj);

/// Initialize the ports for the Port<T>
extern void initializeMyPort(void *obj, double init);

/// Set the time
extern void setMyPortTime(void *obj, double time);

/// Get the time
extern double getMyPortTime(void *obj);

#ifdef __cplusplus
}
#endif

#endif
