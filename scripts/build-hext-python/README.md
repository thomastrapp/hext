# Build Hext Python Wheels with Docker

```
docker run \
  -it \
  --name hext-test \
  --mount type=bind,src="$(pwd)",target=/build \
  thomastrapp/hext-manylinux2014 \
  /build/build-hext-python.sh
ls -lah output/
```

