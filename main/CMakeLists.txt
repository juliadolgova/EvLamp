idf_component_register(
	INCLUDE_DIRS .
	SRCS
		common.c
		main.c
		settings.c
		wifi.c
		bus.c
		effect.c
		surface.c
		input.c
		webserver.c
		api.c
		
		effects/crazybees.c
		effects/dna.c
		effects/fire.c
		effects/lamp.c
		effects/lava.c
		effects/matrix.c
		effects/plasma_waves.c
		effects/rain.c
		effects/rainbow.c
		effects/rays.c
		effects/sparkles.c
		effects/waterfall.c
		effects/metaballs.c
		effects/water.c
		effects/holiday.c
		effects/hoop.c
		effects/twister.c
		effects/flower.c
		effects/polar_lights.c
		effects/gif.c
		
	EMBED_TXTFILES
		web/jquery.js
		web/styles.css
		web/index.html
		
	EMBED_FILES
		gifs/heart.gif
		gifs/heart2.gif
		gifs/boldman.gif
		gifs/coin.gif
		gifs/disk.gif
		gifs/girl.gif
		gifs/hairyman.gif
		gifs/hero.gif
		gifs/disk.gif
		gifs/torch.gif
		gifs/zombie.gif
		gifs/cutebear.gif
)

#spiffs_create_partition_image(storage ../spiffs_image FLASH_IN_PROJECT)
