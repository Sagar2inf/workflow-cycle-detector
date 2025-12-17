#include "httplib.h"
#include "deliver/node_deliver.hpp"
#include "deliver/edge_deliver.hpp"

void set_cors_headers(httplib::Response& res) {
    res.set_header("Access-Control-Allow-Origin", "*");
    res.set_header("Access-Control-Allow-Methods", "GET, POST, PUT, DELETE, OPTIONS");
    res.set_header("Access-Control-Allow-Headers", "Content-Type, Authorization");
    res.set_header("Access-Control-Allow-Credentials", "true");
}

int main() {
    httplib::Server server;

    // Handle all OPTIONS preflight requests
    server.Options(R"(.*)", [](const httplib::Request&, httplib::Response& res) {
        set_cors_headers(res);
        res.status = 204; // No Content
    });

    // Example route
    server.Post("/node/add", [](const auto& req, auto& res) {
        set_cors_headers(res);
        bool f = add_node(req.body);
        res.set_content((f?"nodes added":"something went wrong"), "text/plain");
    });
    server.Post("/node/delete", [](const auto& req, auto& res) {
        set_cors_headers(res);
        bool f = remove_node(req.body);
        res.set_content((f==1?"nodes deleted":"something went wrong"), "text/plain");
    });
    server.Post("/edge/add", [](const auto& req, auto& res) {
        set_cors_headers(res);
        string stat = add_edge(req.body);
        res.set_content(stat, "text/plain");
    });
    server.Post("/edge/delete", [](const auto& req, auto& res) {
        set_cors_headers(res);
        string stat = remove_edge(req.body);
        res.set_content(stat, "text/plain");
    });
    
    cout <<"server is running on port localhost:8080"<<endl; 
    server.listen("0.0.0.0", 8080);
}
