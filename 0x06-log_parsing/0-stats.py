#!/usr/bin/python3
""" Log parsing for stdin """

from signal import signal, SIGINT
import sys
from datetime import datetime

if __name__ == "__main__":

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

    def print_status():
        """print function"""

        print("File size: {}".format(size))
        for k, v in codes.items():
            print("{}: {}".format(k, v))
        return 0

    def line_test(line):
        """Test each line format"""

        if len(line) != 9:
            return False
        if validate_ip(line[0]) is False:
            return False
        if validate_date(line[2][1:] + " " + line[3][:-1]) is False:
            return False
        return True if line[-2] in codes.keys() else False

    def handler(signal_received, frame):
        """signal handler"""
        print_status()
        sys.exit(0)

    size = 0
    count = 0
    codes = {
        '200': 0, '301': 0, '400': 0, '401': 0,
        '403': 0, '404': 0, '405': 0, '500': 0
    }

    for line in sys.stdin:
        signal(SIGINT, handler)

        if count == 10:
            count = print_status()

        line = line.split()
        if line_test(line):
            codes[line[-2]] += 1
            size += int(line[-1])
        count += 1
