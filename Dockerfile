FROM docker/whalesay:latest
LABEL Name=42libasm Version=0.0.1
RUN apt-get -y update && apt-get install -y gdb nasm gcc build-essential fortunes
CMD ["sh", "-c", "/usr/games/fortune -a | cowsay"]
