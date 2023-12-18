   if ($http_origin ~ '^(https|http)?://(alabuga\.prod\.vms|localhost|localhost/)') {
        set $cors "true";
    }
    #http://m11.prod.vms/login
#vms.pk1.prod.asudd
    # Nginx doesn't support nested If statements. This is where things get slightly nasty.
    # Determine the HTTP request method used

    if ($request_method = 'OPTIONS') {
        set $cors "${cors}options";
    }
    if ($request_method = 'GET') {
        set $cors "${cors}get";
    }
    if ($request_method = 'POST') {
        set $cors "${cors}post";
    }
    if ($request_method = 'PUT') {
        set $cors "${cors}put";
    }
    if ($request_method = 'DELETE') {
        set $cors "${cors}delete";
    }

    if ($cors = "true") {
        # Catch all incase there's a request method we're not dealing with properly
        add_header 'Access-Control-Allow-Origin' "$http_origin";
    }

    if ($cors = "trueget") {
        add_header 'Access-Control-Allow-Origin' "$http_origin";
        add_header 'Access-Control-Allow-Credentials' 'true';
        add_header 'Access-Control-Allow-Methods' 'GET, POST, PUT, OPTIONS, DELETE';
        add_header 'Access-Control-Allow-Headers' 'Access-Control-Allow-Headers, Origin, Accept, X-Requested-With, Content-Type, Access-Control-Request-Method, Access-Control-Request-Headers, Authorization, Content-Disposition';
        add_header 'Access-Control-Expose-Headers' 'Content-Disposition';
    }

    if ($cors = "trueoptions") {
        add_header 'Access-Control-Allow-Origin' "$http_origin";

        #
        # Om nom nom cookies
        #

        add_header 'Access-Control-Allow-Credentials' 'true';
        add_header 'Access-Control-Allow-Methods' 'GET, POST, OPTIONS, PUT, HEAD, DELETE';

        #
        # Custom headers and headers various browsers *should* be OK with but aren't

        add_header 'Access-Control-Allow-Headers' 'Access-Control-Allow-Headers, Origin, Accept, X-Requested-With, Content-Type, Access-Control-Request-Method, Access-Control-Request-Headers, Authorization';

        #
        # Tell client that this pre-flight info is valid for 20 days
        #

        add_header 'Access-Control-Max-Age' 1728000;
        add_header 'Content-Type' 'text/plain charset=UTF-8';
        add_header 'Content-Length' 0;
        return 204;
    }

    if ($cors = "truepost") {
        add_header 'Access-Control-Allow-Origin' "$http_origin" always;
        add_header 'Access-Control-Allow-Credentials' 'true';
        add_header 'Access-Control-Allow-Methods' 'GET, POST, PUT, OPTIONS, DELETE';
        add_header 'Access-Control-Allow-Headers' 'Access-Control-Allow-Headers, Origin, Accept, X-Requested-With, Content-Type, Access-Control-Request-Method, Access-Control-Request-Headers, Authorization, Referer, User-Agent';

    }

    if ($cors = "trueput") {
        add_header 'Access-Control-Allow-Origin' "$http_origin" always;
        add_header 'Access-Control-Allow-Credentials' 'true';
        add_header 'Access-Control-Allow-Methods' 'GET, POST, PUT, OPTIONS, DELETE';
        add_header 'Access-Control-Allow-Headers' 'Access-Control-Allow-Headers, Origin, Accept, X-Requested-With, Content-Type, Access-Control-Request-Method, Access-Control-Request-Headers, Authorization, Referer, User-Agent';

    }

    if ($cors = "truedelete") {
        add_header 'Access-Control-Allow-Origin' "$http_origin";
        add_header 'Access-Control-Allow-Credentials' 'true';
        add_header 'Access-Control-Allow-Methods' 'GET, POST, PUT, OPTIONS, DELETE';
        add_header 'Access-Control-Allow-Headers' 'Access-Control-Allow-Headers, Origin, Accept, X-Requested-With, Content-Type, Access-Control-Request-Method, Access-Control-Request-Headers, Authorization';
    }
