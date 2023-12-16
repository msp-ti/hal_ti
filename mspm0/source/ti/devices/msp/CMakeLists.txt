zephyr_include_directories(
  .
  m0p
  m0p/startup_system_files
  m0p/startup_system_files/gcc
  peripherals
  peripherals/m0p
  peripherals/m0p/sysctl
  )

zephyr_library()
zephyr_library_compile_definitions(${COMPILER})
zephyr_library_sources(
  m0p/startup_system_files/gcc/startup_mspm0g350x_gcc.c
  )

