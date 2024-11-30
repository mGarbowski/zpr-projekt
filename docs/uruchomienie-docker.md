# Uruchomienie w Dockerze

## Testy

Zbudowanie obrazu

```shell
docker build --tag zpr-test --file ./Dockerfile.test .
```

Uruchomienie testów

```shell
docker run zpr-test
```

## Aplikacja

Zbudowanie obrazu

```shell
docker build --tag zpr-app --file ./Dockerfile.app .
```

Uruchomienie aplikacji

```shell
xhost +local:docker
docker run -e DISPLAY=$DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix zpr-app
```