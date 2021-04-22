FROM docker/whalesay:latest
LABEL Name=42libasm Version=0.0.1
RUN apt-get -y update && apt-get install -y nasm as31 gcc make build-essential gdb
