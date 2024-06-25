#include <gtest/gtest.h>

#include "../src/ast/parser.hpp"

TEST(ast, init_obj)
{
  cuke::parser p;
}

TEST(ast, feature)
{
//   const char* script = R"*(
//   Feature:
// )*";
//   cwt::details::parser p(script);
//   p.parse();
//   EXPECT_EQ(p.head().type, cuke::ast::node_type::gherkin_document);
//   EXPECT_EQ(p.head().children[0].type, cuke::ast::node_type::feature);
  const char* script = "Feature: First Feature";
  cuke::parser p;
  p.parse_document(script);
  EXPECT_EQ(p.head().type(), cuke::ast::node_type::gherkin_document);
  EXPECT_EQ(p.head().feature().keyword(), std::string("Feature:"));
  EXPECT_EQ(p.head().feature().name(), std::string("First Feature"));
}

// TEST(ast, make_ast)
// {
//   const char* script = R"*(
//   Feature:
// )*";
//   cuke::ast::node head = cwt::details::make_ast(script); 
//   EXPECT_EQ(head.type, cuke::ast::node_type::gherkin_document);
//   EXPECT_EQ(head.children[0].type, cuke::ast::node_type::feature);
// }


// TEST(ast, feature_wo_parser) 
// {
//   const char* script = "Feature:";
//   cwt::details::lexer lex(script);
//   cuke::ast::node node;
//   cwt::details::parse_feature(lex, node);
//   EXPECT_EQ(node.type, cuke::ast::node_type::feature);
// }

// TEST(ast, scenario)
// {
//   const char* script = R"*(
//   Feature:
//   Scenario: 
// )*";
//   cwt::details::parser p(script);
//   p.parse();
//   EXPECT_EQ(p.head().children.size(), 1);
//   EXPECT_EQ(p.head().children[0].type, cuke::ast::node_type::feature); 
// }
// TEST(ast, scenario_wo_parser)
// {
//   const char* script = "Scenario:";
//   cwt::details::lexer lex(script);
//   lex.advance();
//   cuke::ast::node node;
//   cwt::details::parse_scenario(lex, node);
//   EXPECT_EQ(node.type, cuke::ast::node_type::scenario);
// }