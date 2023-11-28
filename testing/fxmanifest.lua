fx_version 'cerulean'
game 'gta5'
author 'Author Name'
description 'Description'
version '1.0.0'
client_scripts {
    'client/client.lua',
};
server_scripts {
    'server/server.lua',
};
shared_scripts {
    'shared/config.lua',
};
dependencies {};
ui_page 'frontend/index.html'
files {
    'frontend/index.html',
    'frontend/*.css',
    'frontend/*.js',
    'frontend/img/*.png',
};
