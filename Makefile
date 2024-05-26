all: ap sta builder

ap:
	docker buildx build -t apemu:test -f Dockerfile.ap --no-cache .

sta:
	docker buildx build -t sta:latest -f Dockerfile.sta --no-cache .

builder:
	docker buildx build -t ap-builder:latest -f Dockerfile.ap_builder --no-cache .

distro:
	docker buildx build -t apemu-distro:latest -f Dockerfile.ap_distro --no-cache .

