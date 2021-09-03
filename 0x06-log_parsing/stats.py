#!/usr/bin/python3
""" Log parsing for stdin """

from signal import signal, SIGINT
import sys
from datetime import datetime

if __name__ == "__main__":

    size = 0
    codes = {
        '200': 0, '301': 0, '400': 0, '401': 0,
        '403': 0, '404': 0, '405': 0, '500': 0
    }

    def validate_date(date):
        """validate date time"""
        try:
            dateStr = "%Y-%m-%d %H:%M:%S.%f"
            return bool(datetime.strptime(date, dateStr))
        except ValueError:
            return False

    def validate_ip(ip):
        """validate ip adress"""

        try:
            ip = ip.split('.')
            return len(ip) == 4 \
                and all(-1 < len(p) < 4 and 0 <= int(p) < 256 for p in ip)
        except ValueError:
            return False    # a part of the ip cant be int
        except (AttributeError, TypeError):
            return False    # ip isnt a string

    def print_status(codes):
        """print function"""
        cod = sorted(codes.keys())
        print("File size: {:d}".format(size))
        for i in cod:
            if codes[i] > 0:
                print("{}: {}".format(i, codes[i]))
        return 0

    def line_test(line):
        """Test each line format"""

        if len(line) < 2:
            return False

        if validate_ip(line[0]) is False:
            return False
        if validate_date(line[2][1:] + " " + line[3][:-1]) is False:
            return False
        return True if line[-2] in codes.keys() and int(line[-2]) else False

    def handler(signal_received, frame):
        """signal handler"""
        print_status(codes)
        sys.exit(0)

    count = 0

    for line in sys.stdin:
        signal(SIGINT, handler)
        count += 1

        line = line.split()
        if line_test(line):
            codes[line[-2]] += 1

        try:
            size += int(line[-1])
        except:
            pass

        if count == 10:
            count = print_status(codes)