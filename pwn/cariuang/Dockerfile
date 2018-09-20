FROM ubuntu:16.04

RUN apt update && \
	apt -y install socat

RUN useradd -ms /bin/bash arkavidia

COPY cariuang /home/arkavidia/
COPY flag /home/arkavidia/
COPY run.sh /home/arkavidia/

EXPOSE 1234

RUN chmod -R 775 /home/arkavidia/
USER arkavidia
WORKDIR /home/arkavidia/

CMD ["./run.sh"]