#include <iostream>

#include <bsoncxx/json.hpp>
#include <bsoncxx/oid.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>
#include <bsoncxx/json.hpp>
#include <bsoncxx/builder/stream/document.hpp>

using namespace mongocxx;
using namespace std;

int main()
{
  instance instance;
  uri uri("mongodb://localhost:27017");
  client client(uri);
  database db = client["cpp"];
  collection collection = db["links"];

  // create a document

  bsoncxx::builder::stream::document document{};
  document << "name" << "john"
           << "age" << 44
           << "city" << "New delhi";

  // Insert the document into the collection
  collection.insert_one(document.view());

  cout << "Document inserted!" << std::endl;

  // Query the collection

  auto cursor = collection.find({}); // Empty query, selects all documents

  for (auto doc : cursor)
  {
    std::cout << bsoncxx::to_json(doc) << std::endl;
  }
}
