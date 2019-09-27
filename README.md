# hardware-oemLock #

This module contains the STMicroelectronics OemLock HAL source code (stub version).
It is part of the STMicroelectronics delivery for Android (see the [delivery][] for more information).

[delivery]: https://wiki.st.com/stm32mpu/wiki/STM32MP15_distribution_for_Android_release_note_-_v1.0.0

## Description ##

This module version includes the first version of the OemLock Android abstraction layer.
It is based on Module OemLock API version 1.0.

Please see the Android delivery release notes for more details.

## Documentation ##

* The [release notes][] provide information on the release.
* The [distribution package][] provides detailed information on how to use this delivery.

[release notes]: https://wiki.st.com/stm32mpu/wiki/STM32MP15_distribution_for_Android_release_note_-_v1.0.0
[distribution package]: https://wiki.st.com/stm32mpu/wiki/STM32MP1_Distribution_Package_for_Android

## Dependencies ##

This module can't be used alone. It is part of the STMicroelectronics delivery for Android.
To be able to use it the device.mk must have the following packages:
```
PRODUCT_PACKAGES += \
    android.hardware.oemlock@<version>-service.stm32mp1
```

## Containing ##

This directory contains the sources and associated Android makefile to generate the android.hardware.oemlock@<version>-service.stm32mp1 binary.

## License ##

This module is distributed under the Apache License, Version 2.0 found in the [LICENSE](./LICENSE) file.
