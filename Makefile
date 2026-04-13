.PHONY: dev server node docs up down

dev:
	@echo "Start server and broker"
	docker compose up --build

up:
	docker compose up -d

down:
	docker compose down

server:
	cd server && npm install && npm run dev

node:
	cd node && pio run

docs:
	@echo "Docs live in ./docs"
