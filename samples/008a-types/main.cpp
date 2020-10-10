/*
See the NOTICE file
distributed with this work for additional information
regarding copyright ownership.  Adam Fowler licenses this file
to you under the Apache License, Version 2.0 (the
"License"); you may not use this file except in compliance
with the License.  You may obtain a copy of the License at

  http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing,
software distributed under the License is distributed on an
"AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
KIND, either express or implied.  See the License for the
specific language governing permissions and limitations
under the License.
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "groundupdb/groundupdb.h" // we want is_container.h, this is the only route

int main()
{
  std::pair<int,std::string> pair(1,"first");
  std::cout << "Type of pair: " << typeid(pair).name() << std::endl;
  std::cout << "Is pair a pair?: " << groundupdb::is_pair<decltype(pair)>::value << std::endl;
  std::cout << "Is pair a container?: " << groundupdb::is_container<decltype(pair)>::value << std::endl;
  std::cout << "Is pair a keyed container?: " << groundupdb::is_keyed_container<decltype(pair)>::value << std::endl << std::endl;

  std::pair<const int,std::string> cpair(1,"first");
  std::cout << "Type of const pair: " << typeid(cpair).name() << std::endl;
  std::cout << "Is const pair a pair?: " << groundupdb::is_pair<decltype(cpair)>::value << std::endl;
  std::cout << "Is const pair a container?: " << groundupdb::is_container<decltype(cpair)>::value << std::endl;
  std::cout << "Is const pair a keyed container?: " << groundupdb::is_keyed_container<decltype(cpair)>::value << std::endl << std::endl;

  std::vector<std::string> vec;
  vec.emplace_back("first");
  std::cout << "Type of vec: " << typeid(vec).name() << std::endl;
  auto viter = vec.begin();
  std::cout << "Type of vec iterator: " << typeid(viter).name() << std::endl;
  std::cout << "Type of vec value: " << typeid(*viter).name() << std::endl;
  std::cout << "Is vec a pair?: " << groundupdb::is_pair<decltype(vec)>::value << std::endl;
  std::cout << "Is vec a container?: " << groundupdb::is_container<decltype(vec)>::value << std::endl;
  std::cout << "Is vec a keyed container?: " << groundupdb::is_keyed_container<decltype(vec)>::value << std::endl << std::endl;

  std::unordered_map<int,std::string> umap;
  umap.emplace(1,"first");
  std::cout << "Type of umap: " << typeid(umap).name() << std::endl;
  auto iter = umap.begin();
  std::cout << "Type of umap iterator: " << typeid(iter).name() << std::endl;
  std::cout << "Type of umap dereference: " << typeid(*iter).name() << std::endl;
  std::cout << "Is umap dereferece a pair?: " << groundupdb::is_pair<decltype(*iter)>::value << std::endl;
  std::cout << "Type of umap key: " << typeid(iter->first).name() << std::endl;
  std::cout << "Type of umap value: " << typeid(iter->second).name() << std::endl;
  std::cout << "Is umap a pair?: " << groundupdb::is_pair<decltype(umap)>::value << std::endl;
  std::cout << "Is umap a container?: " << groundupdb::is_container<decltype(umap)>::value << std::endl;
  std::cout << "Is umap a keyed container?: " << groundupdb::is_keyed_container<decltype(umap)>::value << std::endl << std::endl;
};