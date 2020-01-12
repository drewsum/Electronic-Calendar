import serial
import time

# Assumes device is on COM7
dev = serial.Serial("COM7", 115200, timeout=1)

# Get unix time
unix_time = int(time.time())
print(unix_time)

# Assumes local timezone for Chicago
if time.localtime().tm_isdst:
    local_offset = -5
else:
    local_offset = -6
print(local_offset)

# Pump out UTC with local offset to device
dev.write(b"Set Unix Time: %d, %d\r\n" % (unix_time, local_offset))

dev.close()
