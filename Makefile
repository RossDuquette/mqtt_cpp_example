all:
	@docker compose up mqtt_builder

clean:
	@sudo rm -rf bin/
