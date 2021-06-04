#!/usr/bin/python3
import sys
from datetime import datetime
# example: 
# ['109.197.234.97', '-', '[2021-06-04', '00:53:45.163627]', '"GET', '/projects/260', 'HTTP/1.1"', '403', '345'] -> len = 9

def main():
    for line in sys.stdin:
        line  = line.split()
        if line_test(line):
            print(line)
        

def ip_test(ip):
    try:
        ip = ip.split('.')
        return len(ip) == 4 and all(0 < len(part) < 4 and 0 <= int(part) < 256 for part in ip)
    except ValueError:
        return False    # a part cant be converted to int
    except (AttributeError, TypeError):
        return False    # ip isn't even a string

def validate_days(date):
    try:
        return bool(datetime.strptime(date, "%Y-%m-%d"))
    except ValueError:
        return False
        

def line_test(line):    
    com = '"GET /projects/260 HTTP/1.1"'
    lineCom = line[4] + " " + line[5] + " " + line[6]
    valid = False

    if len(line) != 9:
        return Valid

    if ip_test(line[0]) and line[1] == '-':
        valid = True

    if validate_days(line[2][1:]):
        valid = True

    return (valid)


main()
