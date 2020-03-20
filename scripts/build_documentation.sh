# ZIA
cd $(git rev-parse --show-toplevel)/zia
doxygen config.dox > /dev/null

# CGI
cd $(git rev-parse --show-toplevel)/modules/phpCgiModule/cgi
doxygen config.dox > /dev/null

# SSL
cd $(git rev-parse --show-toplevel)/modules/secureConnectionModule/ssl
doxygen config.dox > /dev/null
