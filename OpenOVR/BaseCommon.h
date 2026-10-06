#pragma once
#include "generated/interfaces/vrtypes.h"

#if defined(BASE_IMPL) || defined(GENFILE)
#include "logging.h"
#endif

// For shared pointers in the generated GVRxyz.gen.h headers
#include <memory>

class CVRCommon {
public:
	// Ensure the resources of the base get freed properly
	virtual ~CVRCommon() {}

	virtual void** _GetStatFuncList() = 0;

	// Given an object which implements CVRCommon as it's not-first interface, the compiler (or at least GCC) can't
	// figure out where the real vtable is with our InheritCVRLayout. It can do virtual function calls just fine for
	// whatever reasons, so use that to implement a deletor.
	// **WARNING**: You are left with a dangling pointer after calling this, it does what it says on the tin.
	virtual void Delete() = 0;
};

#if defined(BASE_IMPL) || defined(GENFILE)

// What a stubbed function hands back once it has logged: a failure for the error enums, so the game
// does not go on to read out parameters nothing wrote, and zero, false or an empty string otherwise.
template <typename T> inline T oovr_stub_default(T*) { return T{}; }
inline const char* oovr_stub_default(const char**) { return ""; }
inline vr::EVROverlayError oovr_stub_default(vr::EVROverlayError*) { return vr::VROverlayError_RequestFailed; }
inline vr::EVRInputError oovr_stub_default(vr::EVRInputError*) { return vr::VRInputError_NoData; }
inline vr::EVRFirmwareError oovr_stub_default(vr::EVRFirmwareError*) { return vr::VRFirmwareError_Fail; }

struct oovr_stub_result {
	template <typename T> operator T() const { return oovr_stub_default((T*)nullptr); }
};

// A game calling something unimplemented used to be aborted behind an error box nobody could see in
// the headset. These log the call once and carry on; stopOnSoftAbort brings the abort back.
#undef STUBBED
#define STUBBED_LOG() OOVR_SOFT_ABORTF("Hit stubbed file at " __FILE__ ":%d func %s", __LINE__, __func__)
#define STUBBED()                  \
	do {                           \
		STUBBED_LOG();             \
		return oovr_stub_result{}; \
	} while (0)
#define STUBBED_VOID() \
	do {               \
		STUBBED_LOG(); \
		return;        \
	} while (0)

#endif

#if defined(GENFILE)
#define BASE_FLAG(...)
#define GEN_INTERFACE(if_name, version, ...)
#endif
