
    add_header Access-Control-Allow-Origin $http_origin;


# Simple requests
if ($request_method ~* "(GET|POST)") {
    add_header "Access-Control-Allow-Origin" * always;
    add_header "Access-Control-Allow-Credentials" "true";
    add_header "Access-Control-Allow-Methods" "GET, POST, OPTIONS, HEAD, DELETE";
    add_header "Access-Control-Allow-Headers" "Authorization,Content-Type,Accept,Origin,User-Agent,DNT,Cache-Control,X-Mx-ReqToken,Keep-Alive,X-Requested-With,If-Modified-Since,order-hash";
    add_header "Access-Control-Expose-Headers" "Content-Length,Content-Range";
}

# Preflighted requests
if ($request_method = "OPTIONS" ) {
    add_header "Access-Control-Allow-Origin" * always;
    add_header "Access-Control-Allow-Credentials" "true";
    add_header "Access-Control-Allow-Methods" "GET, POST, OPTIONS, HEAD, DELETE";
    add_header "Access-Control-Allow-Headers" "Authorization,Content-Type,Accept,Origin,User-Agent,DNT,Cache-Control,X-Mx-ReqToken,Keep-Alive,X-Requested-With,If-Modified-Since,order-hash";
    add_header "Access-Control-Max-Age" 1728000;
    add_header "Content-Length" 0;
    add_header "Content-Type" "text/plain charset=UTF-8";
    return 204;
}

if ($request_method = "DELETE") {
    add_header "Access-Control-Allow-Origin" * always;
    add_header "Access-Control-Allow-Credentials" "true";
    add_header "Access-Control-Allow-Methods" "GET, POST, OPTIONS, HEAD, DELETE";
    add_header "Access-Control-Allow-Headers" "Authorization,Content-Type,Accept,Origin,User-Agent,DNT,Cache-Control,X-Mx-ReqToken,Keep-Alive,X-Requested-With,If-Modified-Since,order-hash";
    add_header "Access-Control-Expose-Headers" "Content-Length,Content-Range";
}

proxy_set_header X-Forwarded-For $http_x_forwarded_for;
proxy_set_header X-Forwarded-Host $http_host;
proxy_set_header X-Forwarded-Proto $scheme;
proxy_set_header X-Forwarded-Port $http_port;
proxy_redirect default;
