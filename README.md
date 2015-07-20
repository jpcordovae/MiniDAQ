# MiniDAQ

Simple and minimalist data acquisition system using TCP protocol

The goal is help people to record data on MySQL/MariaDB without loosing time with complex configurations.

Just connect your tcp client and send data using ',' separator with '\n' at the end of each data stream. This data is put direct to query, you can check the configuration file to get a better idea how it works.

Requirements:

boost library.
C++11
MySQL/MariaDB installed.
MariaDB C connector.

To compile only have to write 'make -B'
