#!/usr/bin/python3
import signal
import sys
from datetime import datetime

def main():
    size = 0
    count = 0
    codes = {'200': 0, '301': 0, '400': 0, '401': 0,
            '403': 0, '404': 0, '405': 0, '500': 0}
    
    for line in sys.stdin:
        line  = line.split()
        if line_test(line):
            if line[-2] in codes.keys():
                codes[line[-2]] += 1
            size += int(line[-1])

        count += 1
        if count == 10:
            count = print_status(size, codes)

def print_status(size, codes):
    print("File size: {}".format(size))
    for k, v in codes.items():
        print("{}: {}".format(k, v))
    return 0

def validate_ip(ip):
    try:
        ip = ip.split('.')
        return len(ip) == 4 and all(0 < len(part) < 4 and 0 <= int(part) < 256 for part in ip)
    except ValueError:
        return False    # a part cant be converted to int
    except (AttributeError, TypeError):
        return False    # ip isn't even a string

def validate_date(date):
    try:
        return bool(datetime.strptime(date, "%Y-%m-%d %H:%M:%S.%f"))
    except ValueError:
        return False

def line_test(line):    
    com = '"GET /projects/260 HTTP/1.1"'
    lineCom = line[4] + " " + line[5] + " " + line[6]
    valid = False

    if len(line) != 9:
        return Valid

    valid = validate_ip(line[0])
    
    if line[1] != '-':
        return False
    
    valid = validate_date(line[2][1:] + " " + line[3][:-1])
    if not valid or com != lineCom:
        return False
    return True if int(line[-1]) else False


main()
