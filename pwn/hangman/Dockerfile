FROM ubuntu:16.04

RUN apt update && \
	apt -y install socat

RUN useradd -ms /bin/bash arkavidia

COPY hangman /home/arkavidia/
COPY flag /home/arkavidia/
COPY hall_of_fame /home/arkavidia/
COPY wordlist /home/arkavidia/
COPY run.sh /home/arkavidia/

EXPOSE 13337

RUN chmod -R 775 /home/arkavidia/
USER arkavidia
WORKDIR /home/arkavidia/

CMD ["./run.sh"]