# OBD2 API

## Include Library

```arduino
#include <OBD2.h>
```

## Setup

### Begin

Initialize the library, this read try to read all the supported PID's of the vehicle.

```arduino
OBD2.begin();
```

Returns `1` on success, `0` on failure.

### End

Stop the library.

```arduino
OBD2.end()
```

## Reading data

### PID constants

For more information see: https://en.wikipedia.org/wiki/OBD-II_PIDs

 * `PIDS_SUPPORT_01_20`
 * `MONITOR_STATUS_SINCE_DTCS_CLEARED`
 * `FREEZE_DTC`
 * `FUEL_SYSTEM_STATUS`
 * `CALCULATED_ENGINE_LOAD`
 * `ENGINE_COOLANT_TEMPERATURE`
 * `SHORT_TERM_FUEL_TRIM_BANK_1`
 * `LONG_TERM_FUEL_TRIM_BANK_1`
 * `SHORT_TERM_FUEL_TRIM_BANK_2`
 * `LONG_TERM_FUEL_TRIM_BANK_2`
 * `INTAKE_MANIFOLD_ABSOLUTE_PRESSURE`
 * `ENGINE_RPM`
 * `VEHICLE_SPEED`
 * `TIMING_ADVANCE`
 * `AIR_INTAKE_TEMPERATURE`
 * `MAF_AIR_FLOW_RATE`
 * `THROTTLE_POSITION`
 * `COMMANDED_SECONDARY_AIR_STATUS`
 * `OXYGEN_SENSORS_PRESENT_IN_2_BANKS`
 * `OXYGEN_SENSOR_1_SHORT_TERM_FUEL_TRIM`
 * `OXYGEN_SENSOR_2_SHORT_TERM_FUEL_TRIM`
 * `OXYGEN_SENSOR_3_SHORT_TERM_FUEL_TRIM`
 * `OXYGEN_SENSOR_4_SHORT_TERM_FUEL_TRIM`
 * `OXYGEN_SENSOR_5_SHORT_TERM_FUEL_TRIM`
 * `OXYGEN_SENSOR_6_SHORT_TERM_FUEL_TRIM`
 * `OXYGEN_SENSOR_7_SHORT_TERM_FUEL_TRIM`
 * `OXYGEN_SENSOR_8_SHORT_TERM_FUEL_TRIM`
 * `OBD_STANDARDS_THIS_VEHICLE_CONFORMS_TO`
 * `OXYGEN_SENSORS_PRESENT_IN_4_BANKS`
 * `AUXILIARY_INPUT_STATUS`
 * `RUN_TIME_SINCE_ENGINE_START`
 * `PIDS_SUPPORT_21_40`
 * `DISTANCE_TRAVELED_WITH_MIL_ON`
 * `FUEL_RAIL_PRESSURE`
 * `FUEL_RAIL_GAUGE_PRESSURE`
 * `OXYGEN_SENSOR_1_FUEL_AIR_EQUIVALENCE_RATIO`
 * `OXYGEN_SENSOR_2_FUEL_AIR_EQUIVALENCE_RATIO`
 * `OXYGEN_SENSOR_3_FUEL_AIR_EQUIVALENCE_RATIO`
 * `OXYGEN_SENSOR_4_FUEL_AIR_EQUIVALENCE_RATIO`
 * `OXYGEN_SENSOR_5_FUEL_AIR_EQUIVALENCE_RATIO`
 * `OXYGEN_SENSOR_6_FUEL_AIR_EQUIVALENCE_RATIO`
 * `OXYGEN_SENSOR_7_FUEL_AIR_EQUIVALENCE_RATIO`
 * `OXYGEN_SENSOR_8_FUEL_AIR_EQUIVALENCE_RATIO`
 * `COMMANDED_EGR`
 * `EGR_ERROR`
 * `COMMANDED_EVAPORATIVE_PURGE`
 * `FUEL_TANK_LEVEL_INPUT`
 * `WARM_UPS_SINCE_CODES_CLEARED`
 * `DISTANCE_TRAVELED_SINCE_CODES_CLEARED`
 * `EVAP_SYSTEM_VAPOR_PRESSURE`
 * `ABSOLULTE_BAROMETRIC_PRESSURE`
 * `CATALYST_TEMPERATURE_BANK_1_SENSOR_1`
 * `CATALYST_TEMPERATURE_BANK_2_SENSOR_1`
 * `CATALYST_TEMPERATURE_BANK_1_SENSOR_2`
 * `CATALYST_TEMPERATURE_BANK_2_SENSOR_2`
 * `PIDS_SUPPORT_41_60`
 * `MONITOR_STATUS_THIS_DRIVE_CYCLE`
 * `CONTROL_MODULE_VOLTAGE`
 * `ABSOLUTE_LOAD_VALUE`
 * `FUEL_AIR_COMMANDED_EQUIVALENCE_RATE`
 * `RELATIVE_THROTTLE_POSITION`
 * `AMBIENT_AIR_TEMPERATURE`
 * `ABSOLUTE_THROTTLE_POSITION_B`
 * `ABSOLUTE_THROTTLE_POSITION_C`
 * `ABSOLUTE_THROTTLE_POSITION_D`
 * `ABSOLUTE_THROTTLE_POSITION_E`
 * `ABSOLUTE_THROTTLE_POSITION_F`
 * `COMMANDED_THROTTLE_ACTUATOR`
 * `TIME_RUN_WITH_MIL_ON`
 * `TIME_SINCE_TROUBLE_CODES_CLEARED`
 * `FUEL_TYPE`
 * `ETHANOL_FUEL_PERCENTAGE`
 * `ABSOLUTE_EVAP_SYSTEM_VAPOR_PRESSURE`
 * `FUEL_RAIL_ABSOLUTE_PRESSURE`
 * `RELATIVE_ACCELERATOR_PEDAL_POSITTION`
 * `HYBRID_BATTERY_PACK_REMAINING_LIFE`
 * `ENGINE_OIL_TEMPERATURE`
 * `FUEL_INJECTION_TIMING`
 * `ENGINE_FUEL_RATE`
 * `EMISSION_REQUIREMENT_TO_WHICH_VEHICLE_IS_DESIGNED`

### Check if a PID is supported by the vehicle

```arduino
bool pidSupported = OBD2.pidSupported(pid);
```

 * `pid` - PID to check support for

Returns `true` if the vehicle supports the `pid`, otherwise `false`.


### Check if the PID value is represented in raw form

```arduino
bool pidValueRaw = OBD2.pidValueRaw(pid);
```

 * `pid` - PID to check support for

Returns `true` if the library does NOT support converting the `pid` value, otherwise `false`.

If raw format is used, use `OBD2.pidReadRaw(pid)` to read the raw value. Otherwise, `OBD2.pidRead(pid)` can be used to read a converted value as a `float`.

### PID name

Get the name of a PID.

```arduino
String name = OBD2.pidName(pid);
```
 * `pid` - PID to get name of

Returns the name of the PID as a string or `"Unknown"` if not known.

### PID units

Get the units of a PID.

```arduino
String units = OBD2.pidUnits(pid);
```
 * `pid` - PID to get units of

Returns the units of the PID as a string.

### PID value

Read the value of a PID.

```arduino
float value = OBD2.pidRead(pid);
```
 * `pid` - PID to get value of

Returns the value of the PID as a `float` or `NAN` on error.

The raw PID value is coverted to a float value based on the data format of the PID.

### PID raw value

Read the raw value of a PID.

```arduino
unsigned long value = OBD2.pidRead(pid);
```
 * `pid` - PID to get raw value of

Returns the value of the PID as a `unsigned long`.

### VIN

Read the vehicle's VIN.

```arduino
String vin = OBD2.vinRead();
```

Returns vehicle's VIN, or empty string on failure.

### ECU Name

Read the vehicle's ECU name.

```arduino
String vin = OBD2.ecuNameRead();
```

Returns vehicle's ECU name, or empty string on failure.

### Response timeout

Set the response timeout in milliseconds.

```
OBD2.setTimeout(timeout);
```

 * `timeout` - new response in milliseconds. Defaults to 2000 if not set.
