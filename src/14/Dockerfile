FROM ubuntu as compiler

RUN apt-get update && apt-get install -y \
  gcc \
  gdb \
  ltrace \
  nano \
  libssl-dev\
  && rm -rf /var/lib/apt/lists/*

FROM compiler
RUN groupadd -r grp && useradd -l -r -g grp app
COPY --chown=app:grp folders.c /app/
COPY --chown=app:grp wordlist.c /app/
WORKDIR /app
USER app

RUN gcc folders.c -o folders
RUN gcc wordlist.c  -lcrypto -o wordlist
# the CMD can be overridden: docker run -it folders /bin/bash
CMD ["./folders", "/etc"]