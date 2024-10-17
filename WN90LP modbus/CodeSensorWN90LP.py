from pymodbus.client import ModbusSerialClient as ModbusClient
import time

# Initialize Modbus client
client = ModbusClient(
    port='COM10',  # Update with your port name
    baudrate=9600,
    parity='N',
    stopbits=1,
    bytesize=8,
    timeout=1
)

# Connect to the client
client.connect()

# Function to read registers
def read_register(start_address, count=1):
    result = client.read_holding_registers(start_address, count, slave=0x90)  # Replace with your device's address
    if result.isError():
        print(f"Error reading from address {start_address}")
        return None
    return result.registers

# Convert the result based on the specific sensor data
def convert_value(registers, factor=1, offset=0):
    value = registers[0] * factor + offset
    return value

# Example of reading all sensor data
def read_weather_data():
    # Light intensity (register 0x0165)
    light_registers = read_register(0x0165)
    if light_registers:
        light_intensity = convert_value(light_registers, 0.1)
        print(f"Light Intensity: {light_intensity} lux")
    
    # UV Index (register 0x0166)
    uv_registers = read_register(0x0166)
    if uv_registers:
        uv_index = convert_value(uv_registers, 0.1)
        print(f"UV Index: {uv_index}")
    
    # Temperature (register 0x0167)
    temp_registers = read_register(0x0167)
    if temp_registers:
        temperature = convert_value(temp_registers, 0.1, -40.0)
        print(f"Temperature: {temperature} °C")
    
    # Humidity (register 0x0168)
    humidity_registers = read_register(0x0168)
    if humidity_registers:
        humidity = convert_value(humidity_registers, 1)
        print(f"Humidity: {humidity} %")
    
    # Wind Speed (register 0x0169)
    wind_speed_registers = read_register(0x0169)
    if wind_speed_registers:
        wind_speed = convert_value(wind_speed_registers, 0.1)
        print(f"Wind Speed: {wind_speed} m/s")
    
    # Gust Speed (register 0x016A)
    gust_speed_registers = read_register(0x016A)
    if gust_speed_registers:
        gust_speed = convert_value(gust_speed_registers, 0.1)
        print(f"Gust Speed: {gust_speed} m/s")
    
    # Wind Direction (register 0x016B)
    wind_dir_registers = read_register(0x016B)
    if wind_dir_registers:
        wind_direction = convert_value(wind_dir_registers, 1)
        print(f"Wind Direction: {wind_direction} °")
    
    # Rainfall (register 0x016C)
    rainfall_registers = read_register(0x016C)
    if rainfall_registers:
        rainfall = convert_value(rainfall_registers, 0.1)
        print(f"Rainfall: {rainfall} mm")
    
    # ABS Pressure (register 0x016D)
    abs_pressure_registers = read_register(0x016D)
    if abs_pressure_registers:
        abs_pressure = convert_value(abs_pressure_registers, 0.1)
        print(f"ABS Pressure: {abs_pressure} hPa")

# Call the function to read data
while(1):
    read_weather_data()
    time.sleep(2)


# Close the Modbus client
client.close()
