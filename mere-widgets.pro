TEMPLATE = subdirs
CONFIG+=ordered
SUBDIRS = \
        mere-widgets-lib   	\  # mere-widgets-lib
        mere-widgets-app     	\  # mere-widgets-app
#        mere-widgets-tests    	\  # mere-widgets-tests

mere-widgets-app.depends   = mere-widgets-lib
#mere-widgets-tests.depends = mere-widgets-lib
