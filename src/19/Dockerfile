FROM ubuntu as compiler

RUN apt-get update && apt-get install -y \
  make \
  gcc \
  gdb \
  ltrace \
  nano \
  libssl-dev\
  && rm -rf /var/lib/apt/lists/*

FROM compiler
RUN groupadd -r grp && useradd -l -r -g grp app
WORKDIR /app
USER app

# the CMD can be overridden: 
# docker run -it --rm -v ${PWD}:/app wordlist /bin/bash
CMD ["make"]