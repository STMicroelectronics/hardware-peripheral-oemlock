#include "OemLock.h"

#define OEMLOCK_ID "vendor.oemlock-hal-1-0.stub"

namespace android {
namespace hardware {
namespace oemlock {
namespace V1_0 {
namespace implementation {


OemLock::OemLock()
  : mAllowed(false) {
}

// Methods from ::android::hardware::oemlock::V1_0::IOemLock follow.
Return<void> OemLock::getName(getName_cb _hidl_cb) {
    _hidl_cb(OemLockStatus::OK, OEMLOCK_ID);

    return Void();
}

Return<OemLockSecureStatus> OemLock::setOemUnlockAllowedByCarrier(bool allowed, const hidl_vec<uint8_t>& signature) {
    for (size_t i = 0; i < signature.size(); ++i) {
        if (signature[i] != OEMLOCK_ID[i])
            return OemLockSecureStatus::INVALID_SIGNATURE;
    }

    mAllowed = allowed;

    return OemLockSecureStatus::OK;
}

Return<void> OemLock::isOemUnlockAllowedByCarrier(isOemUnlockAllowedByCarrier_cb _hidl_cb) {
    _hidl_cb(OemLockStatus::OK, mAllowed);

    return Void();
}

Return<::android::hardware::oemlock::V1_0::OemLockStatus> OemLock::setOemUnlockAllowedByDevice(bool allowed) {
    mAllowed = allowed;

    return OemLockStatus::OK;
}

Return<void> OemLock::isOemUnlockAllowedByDevice(isOemUnlockAllowedByDevice_cb _hidl_cb) {
    _hidl_cb(OemLockStatus::OK, mAllowed);

    return Void();
}

}  // namespace implementation
}  // namespace V1_0
}  // namespace oemlock
}  // namespace hardware
}  // namespace android
