FROM ubuntu:16.04

RUN apt update && \
	apt -y install socat

RUN useradd -ms /bin/bash arkavidia

RUN mkdir /home/arkavidia/chall

COPY vault /home/arkavidia/chall
COPY flag /home/arkavidia/chall
COPY run.sh /home/arkavidia/chall

EXPOSE 31003

RUN chown -R root:root /home/arkavidia/chall
RUN chmod -R 555 /home/arkavidia/chall
USER arkavidia
WORKDIR /home/arkavidia/chall

CMD ["./run.sh"]