project('Généricité TP2', 'cpp', default_options: ['cpp_std=c++1z'], license: 'MIT')

if meson.get_compiler('cpp').get_id() == 'gcc'
	add_global_arguments('-fconcepts', language: 'cpp')
endif

subdir('./src')
subdir('./tests')
