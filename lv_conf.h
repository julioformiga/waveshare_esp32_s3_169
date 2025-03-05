#ifndef LV_CONF_H
	#define LV_CONF_H

	#define LV_USE_THEME_DEFAULT 1
	#if LV_USE_THEME_DEFAULT
	    #define LV_THEME_DEFAULT_DARK 1
	#endif

	#define LV_FONT_MONTSERRAT_14 1
	#define LV_FONT_MONTSERRAT_16 1
	#define LV_FONT_MONTSERRAT_18 1
	#define LV_FONT_MONTSERRAT_40 1
  #define LV_FONT_MONTSERRAT_48 1
	#define LV_FONT_DEFAULT &lv_font_montserrat_14
	#define LV_BUILD_EXAMPLES 1
	#define LV_USE_DEMO_WIDGETS 1

	#ifdef LV_EMULATOR
		/*Color depth: 1 (I1), 8 (L8), 16 (RGB565), 24 (RGB888), 32 (XRGB8888)*/
		#define LV_COLOR_DEPTH 24
		#if LV_USE_STDLIB_MALLOC == LV_STDLIB_BUILTIN
			#define LV_MEM_SIZE (240 * 1024U)          /*[bytes]*/
		#endif
		#define LV_USE_LOG 1
		#define LV_USE_SDL              1
		#if LV_USE_SDL
				#define LV_SDL_INCLUDE_PATH     <SDL2/SDL.h>
				#define LV_SDL_RENDER_MODE      LV_DISPLAY_RENDER_MODE_DIRECT   /*LV_DISPLAY_RENDER_MODE_DIRECT is recommended for best performance*/
				#define LV_SDL_BUF_COUNT        1    /*1 or 2*/
				#define LV_SDL_ACCELERATED      1    /*1: Use hardware acceleration*/
				#define LV_SDL_FULLSCREEN       0    /*1: Make the window full screen by default*/
				#define LV_SDL_DIRECT_EXIT      1    /*1: Exit the application when all SDL windows are closed*/
				#define LV_SDL_MOUSEWHEEL_MODE  LV_SDL_MOUSEWHEEL_MODE_ENCODER  /*LV_SDL_MOUSEWHEEL_MODE_ENCODER/CROWN*/
		#endif
	#else
		#define LV_COLOR_DEPTH 16
		#if LV_USE_STDLIB_MALLOC == LV_STDLIB_BUILTIN
			#define LV_MEM_SIZE (120 * 1024U)          /*[bytes]*/
		#endif
		#define LV_USE_LOG 0
		#if LV_USE_OS == LV_OS_FREERTOS
			/*
			 * Unblocking an RTOS task with a direct notification is 45% faster and uses less RAM
			 * than unblocking a task using an intermediary object such as a binary semaphore.
			 * RTOS task notifications can only be used when there is only one task that can be the recipient of the event.
			 */
			#define LV_USE_FREERTOS_TASK_NOTIFY 0
		#endif
		#define LV_USE_PROFILER 0
		#define LV_USE_SDL              0
		#define LV_USE_ST7789        1
		#define LV_USE_GENERIC_MIPI (LV_USE_ST7735 | LV_USE_ST7789 | LV_USE_ST7796 | LV_USE_ILI9341)

	#endif
#endif
