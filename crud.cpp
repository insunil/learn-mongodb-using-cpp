#include <iostream>
#include<string>
#include <cstdlib>

#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <bsoncxx/oid.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>
#include <cstdlib>
#include <bsoncxx/builder/stream/document.hpp>

using namespace mongocxx;
using namespace std;
using namespace bsoncxx;

class MongoDBHandler
{
private:
  instance instance;
  uri uri{getenv("connectionstring")}; // uri uri("mongodb://localhost:27017") is not allowed in class
  client client{uri};
  database db;
  collection coll;

public:
  MongoDBHandler(std::string db_name, std::string coll_name)
  {
    db = client[db_name];
    coll = db[coll_name];
  }
  void insert_document()
  {
    std::string name, city;
    int age;

    cout << "Enter name,address,age" << endl;
    cin >> name >> city >> age;
    builder::stream::document document{};
    document << "name" << name
             << "age" << age
             << "city" << city;

    coll.insert_one(document.view());
    cout << "Document inserted!" << std::endl;
  };
  void query_collection()
  {
    auto cursor = coll.find({});

    for (auto doc : cursor)
    {
      cout << to_json(doc) << std::endl;
    }
  };
};

int main()
{
  MongoDBHandler handler("product", "productdetails");

  while (1)
  {
    int option;
    cout << "please choose an option" << endl;
    cout << "1. Insert a document" << endl;
    cout << "2. Query the collection" << endl;
    cout << "3. Exit" << endl;
    cin >> option;

    switch (option)
    {
    case 1:
      handler.insert_document();
      break;
    case 2:
      handler.query_collection();
      break;

    case 3:
      return 0;

    default:
      cout << "Invalid option" << endl;
      cout << "Please choose a valid option" << endl;
      break;
    }
  }

  return 0;
}
