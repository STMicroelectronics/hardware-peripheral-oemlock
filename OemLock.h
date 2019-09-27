#ifndef ANDROID_HARDWARE_OEMLOCK_V1_0_OEMLOCK_H
#define ANDROID_HARDWARE_OEMLOCK_V1_0_OEMLOCK_H

#include <android/hardware/oemlock/1.0/IOemLock.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>

namespace android {
namespace hardware {
namespace oemlock {
namespace V1_0 {
namespace implementation {

using ::android::hardware::hidl_array;
using ::android::hardware::hidl_memory;
using ::android::hardware::hidl_string;
using ::android::hardware::hidl_vec;
using ::android::hardware::Return;
using ::android::hardware::Void;
using ::android::sp;

struct OemLock : public IOemLock {
    OemLock();
    // Methods from ::android::hardware::oemlock::V1_0::IOemLock follow.
    Return<void> getName(getName_cb _hidl_cb) override;
    Return<::android::hardware::oemlock::V1_0::OemLockSecureStatus> setOemUnlockAllowedByCarrier(bool allowed, const hidl_vec<uint8_t>& signature) override;
    Return<void> isOemUnlockAllowedByCarrier(isOemUnlockAllowedByCarrier_cb _hidl_cb) override;
    Return<::android::hardware::oemlock::V1_0::OemLockStatus> setOemUnlockAllowedByDevice(bool allowed) override;
    Return<void> isOemUnlockAllowedByDevice(isOemUnlockAllowedByDevice_cb _hidl_cb) override;

private:
    bool mAllowed;

};
}  // namespace implementation
}  // namespace V1_0
}  // namespace oemlock
}  // namespace hardware
}  // namespace android

#endif  // ANDROID_HARDWARE_OEMLOCK_V1_0_OEMLOCK_H
