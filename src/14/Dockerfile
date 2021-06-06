FROM ubuntu

RUN apt-get update && apt-get install -y \
  gcc \
  gdb \
  ltrace \
  nano \
  && rm -rf /var/lib/apt/lists/*

RUN groupadd -r grp && useradd -l -r -g grp app
COPY --chown=app:grp folders.c /app/
WORKDIR /app
USER app

RUN gcc folders.c -o folders
# the CMD can be overridden: docker run -it folders /bin/bash
CMD ["./folders", "/etc"]