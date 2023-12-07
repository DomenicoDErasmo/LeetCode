#![allow(dead_code)]

struct Solution {}

#[derive(PartialEq, Debug, Clone, Copy)]
enum Operator {
    Increment,
    Decrement,
}

impl Operator {
    pub fn operation(&self, other: i32) -> i32 {
        match self {
            Self::Increment => other + 1,
            Self::Decrement => other - 1,
        }
    }
}

#[derive(PartialEq, Debug, Clone, Copy)]
enum Token {
    Identifier,
    Operator(Operator),
    ExpressionEnd,
}

struct Lexer {
    tokens: Vec<Token>,
}

impl Lexer {
    pub fn lex_tokens(&mut self, operations: Vec<String>) {
        for operation in operations {
            let current_position = 0;
            self.lex_token(operation, current_position);
        }
    }

    fn lex_token(&mut self, operation: String, mut current_position: usize) {
        while current_position < operation.len() {
            match operation.chars().nth(current_position) {
                Some('+') => {
                    self.tokens.push(Token::Operator(Operator::Increment));
                    current_position += 2;
                },
                Some('-') => {
                    self.tokens.push(Token::Operator(Operator::Decrement));
                    current_position += 2;
                },
                Some('X') => {
                    self.tokens.push(Token::Identifier);
                    current_position += 1;
                },
                _ => {break;}
            }
        }
        self.tokens.push(Token::ExpressionEnd);
    }
}

struct Parser {
    tokens: Vec<Token>,
}

impl Parser {
    pub fn parse_tokens(&mut self) -> i32 {
        let mut result = 0;
        let mut queue = std::collections::VecDeque::<Token>::new();
        for token in self.tokens.iter() {
            match token {
                Token::Operator(operator) => {
                    match queue.pop_front() {
                        Some(Token::Identifier) => {
                            result = operator.operation(result);
                        },
                        None => {
                            queue.push_front(token.clone());
                        },
                        _ => {},
                    }
                },
                Token::Identifier => {
                    match queue.pop_front() {
                        Some(Token::Operator(operator)) => {
                            result = operator.operation(result);
                        },
                        None => {
                            queue.push_front(token.clone());
                        },
                        _ => {},
                    }
                },
                _ => {},
            };
        }
        result
    }
}

impl Solution {
    pub fn final_value_after_operations(operations: Vec<String>) -> i32 {
        let mut lexer = Lexer {tokens: vec![]};
        lexer.lex_tokens(operations);
        
        let mut parser = Parser {tokens: lexer.tokens};
        parser.parse_tokens()
    }
}

#[cfg(test)]
mod p2011_tests {
    use super::*;

    #[test]
    fn test_final_value_after_operations() {
        assert_eq!(Solution::final_value_after_operations(vec!["--X".to_owned(),"X++".to_owned(),"X++".to_owned()]), 1);
    }

    #[test]
    fn test_lex_tokens() {
        let mut parser = Lexer {tokens: vec![]};
        let input = vec!["--X".to_owned(), "X++".to_owned(), "X--".to_owned(), "++X".to_owned()];
        parser.lex_tokens(input);

        assert_eq!(parser.tokens.len(), 12);
        assert_eq!(parser.tokens, vec![
            Token::Operator(Operator::Decrement), Token::Identifier, Token::ExpressionEnd, 
            Token::Identifier, Token::Operator(Operator::Increment), Token::ExpressionEnd,
            Token::Identifier, Token::Operator(Operator::Decrement), Token::ExpressionEnd,
            Token::Operator(Operator::Increment), Token::Identifier, Token::ExpressionEnd,    
        ]);
    }

    #[test]
    fn test_parse_tokens() {
        let mut parser = Parser {tokens: vec![Token::Operator(Operator::Increment), Token::Identifier]};
        assert_eq!(parser.parse_tokens(), 1);
        let mut parser = Parser {tokens: vec![Token::Identifier, Token::Operator(Operator::Increment)]};
        assert_eq!(parser.parse_tokens(), 1);
        let mut parser = Parser {tokens: vec![Token::Operator(Operator::Decrement), Token::Identifier]};
        assert_eq!(parser.parse_tokens(), -1);
        let mut parser = Parser {tokens: vec![Token::Identifier, Token::Operator(Operator::Decrement)]};
        assert_eq!(parser.parse_tokens(), -1);
    }
}