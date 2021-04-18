/*
 * Copyright (c) 2021, Tim Flynn <trflynn89@pm.me>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#include <AK/HashMap.h>
#include <AK/StringView.h>

namespace SQL {

// https://sqlite.org/lang_keywords.html
#define ENUMERATE_SQL_TOKENS                                              \
    __ENUMERATE_SQL_TOKEN("ABORT", Abort, Keyword)                        \
    __ENUMERATE_SQL_TOKEN("ACTION", Action, Keyword)                      \
    __ENUMERATE_SQL_TOKEN("ADD", Add, Keyword)                            \
    __ENUMERATE_SQL_TOKEN("AFTER", After, Keyword)                        \
    __ENUMERATE_SQL_TOKEN("ALL", All, Keyword)                            \
    __ENUMERATE_SQL_TOKEN("ALTER", Alter, Keyword)                        \
    __ENUMERATE_SQL_TOKEN("ALWAYS", Always, Keyword)                      \
    __ENUMERATE_SQL_TOKEN("ANALYZE", Analyze, Keyword)                    \
    __ENUMERATE_SQL_TOKEN("AND", And, Keyword)                            \
    __ENUMERATE_SQL_TOKEN("AS", As, Keyword)                              \
    __ENUMERATE_SQL_TOKEN("ASC", Asc, Keyword)                            \
    __ENUMERATE_SQL_TOKEN("ATTACH", Attach, Keyword)                      \
    __ENUMERATE_SQL_TOKEN("AUTOINCREMENT", Autoincrement, Keyword)        \
    __ENUMERATE_SQL_TOKEN("BEFORE", Before, Keyword)                      \
    __ENUMERATE_SQL_TOKEN("BEGIN", Begin, Keyword)                        \
    __ENUMERATE_SQL_TOKEN("BETWEEN", Between, Keyword)                    \
    __ENUMERATE_SQL_TOKEN("BY", By, Keyword)                              \
    __ENUMERATE_SQL_TOKEN("CASCADE", Cascade, Keyword)                    \
    __ENUMERATE_SQL_TOKEN("CASE", Case, Keyword)                          \
    __ENUMERATE_SQL_TOKEN("CAST", Cast, Keyword)                          \
    __ENUMERATE_SQL_TOKEN("CHECK", Check, Keyword)                        \
    __ENUMERATE_SQL_TOKEN("COLLATE", Collate, Keyword)                    \
    __ENUMERATE_SQL_TOKEN("COLUMN", Column, Keyword)                      \
    __ENUMERATE_SQL_TOKEN("COMMIT", Commit, Keyword)                      \
    __ENUMERATE_SQL_TOKEN("CONFLICT", Conflict, Keyword)                  \
    __ENUMERATE_SQL_TOKEN("CONSTRAINT", Constraint, Keyword)              \
    __ENUMERATE_SQL_TOKEN("CREATE", Create, Keyword)                      \
    __ENUMERATE_SQL_TOKEN("CROSS", Cross, Keyword)                        \
    __ENUMERATE_SQL_TOKEN("CURRENT", Current, Keyword)                    \
    __ENUMERATE_SQL_TOKEN("CURRENT_DATE", CurrentDate, Keyword)           \
    __ENUMERATE_SQL_TOKEN("CURRENT_TIME", CurrentTime, Keyword)           \
    __ENUMERATE_SQL_TOKEN("CURRENT_TIMESTAMP", CurrentTimestamp, Keyword) \
    __ENUMERATE_SQL_TOKEN("DATABASE", Database, Keyword)                  \
    __ENUMERATE_SQL_TOKEN("DEFAULT", Default, Keyword)                    \
    __ENUMERATE_SQL_TOKEN("DEFERRABLE", Deferrable, Keyword)              \
    __ENUMERATE_SQL_TOKEN("DEFERRED", Deferred, Keyword)                  \
    __ENUMERATE_SQL_TOKEN("DELETE", Delete, Keyword)                      \
    __ENUMERATE_SQL_TOKEN("DESC", Desc, Keyword)                          \
    __ENUMERATE_SQL_TOKEN("DETACH", Detach, Keyword)                      \
    __ENUMERATE_SQL_TOKEN("DISTINCT", Distinct, Keyword)                  \
    __ENUMERATE_SQL_TOKEN("DO", Do, Keyword)                              \
    __ENUMERATE_SQL_TOKEN("DROP", Drop, Keyword)                          \
    __ENUMERATE_SQL_TOKEN("EACH", Each, Keyword)                          \
    __ENUMERATE_SQL_TOKEN("ELSE", Else, Keyword)                          \
    __ENUMERATE_SQL_TOKEN("END", End, Keyword)                            \
    __ENUMERATE_SQL_TOKEN("ESCAPE", Escape, Keyword)                      \
    __ENUMERATE_SQL_TOKEN("EXCEPT", Except, Keyword)                      \
    __ENUMERATE_SQL_TOKEN("EXCLUDE", Exclude, Keyword)                    \
    __ENUMERATE_SQL_TOKEN("EXCLUSIVE", Exclusive, Keyword)                \
    __ENUMERATE_SQL_TOKEN("EXISTS", Exists, Keyword)                      \
    __ENUMERATE_SQL_TOKEN("EXPLAIN", Explain, Keyword)                    \
    __ENUMERATE_SQL_TOKEN("FAIL", Fail, Keyword)                          \
    __ENUMERATE_SQL_TOKEN("FILTER", Filter, Keyword)                      \
    __ENUMERATE_SQL_TOKEN("FIRST", First, Keyword)                        \
    __ENUMERATE_SQL_TOKEN("FOLLOWING", Following, Keyword)                \
    __ENUMERATE_SQL_TOKEN("FOR", For, Keyword)                            \
    __ENUMERATE_SQL_TOKEN("FOREIGN", Foreign, Keyword)                    \
    __ENUMERATE_SQL_TOKEN("FROM", From, Keyword)                          \
    __ENUMERATE_SQL_TOKEN("FULL", Full, Keyword)                          \
    __ENUMERATE_SQL_TOKEN("GENERATED", Generated, Keyword)                \
    __ENUMERATE_SQL_TOKEN("GLOB", Glob, Keyword)                          \
    __ENUMERATE_SQL_TOKEN("GROUP", Group, Keyword)                        \
    __ENUMERATE_SQL_TOKEN("GROUPS", Groups, Keyword)                      \
    __ENUMERATE_SQL_TOKEN("HAVING", Having, Keyword)                      \
    __ENUMERATE_SQL_TOKEN("IF", If, Keyword)                              \
    __ENUMERATE_SQL_TOKEN("IGNORE", Ignore, Keyword)                      \
    __ENUMERATE_SQL_TOKEN("IMMEDIATE", Immediate, Keyword)                \
    __ENUMERATE_SQL_TOKEN("IN", In, Keyword)                              \
    __ENUMERATE_SQL_TOKEN("INDEX", Index, Keyword)                        \
    __ENUMERATE_SQL_TOKEN("INDEXED", Indexed, Keyword)                    \
    __ENUMERATE_SQL_TOKEN("INITIALLY", Initially, Keyword)                \
    __ENUMERATE_SQL_TOKEN("INNER", Inner, Keyword)                        \
    __ENUMERATE_SQL_TOKEN("INSERT", Insert, Keyword)                      \
    __ENUMERATE_SQL_TOKEN("INSTEAD", Instead, Keyword)                    \
    __ENUMERATE_SQL_TOKEN("INTERSECT", Intersect, Keyword)                \
    __ENUMERATE_SQL_TOKEN("INTO", Into, Keyword)                          \
    __ENUMERATE_SQL_TOKEN("IS", Is, Keyword)                              \
    __ENUMERATE_SQL_TOKEN("ISNULL", Isnull, Keyword)                      \
    __ENUMERATE_SQL_TOKEN("JOIN", Join, Keyword)                          \
    __ENUMERATE_SQL_TOKEN("KEY", Key, Keyword)                            \
    __ENUMERATE_SQL_TOKEN("LAST", Last, Keyword)                          \
    __ENUMERATE_SQL_TOKEN("LEFT", Left, Keyword)                          \
    __ENUMERATE_SQL_TOKEN("LIKE", Like, Keyword)                          \
    __ENUMERATE_SQL_TOKEN("LIMIT", Limit, Keyword)                        \
    __ENUMERATE_SQL_TOKEN("MATCH", Match, Keyword)                        \
    __ENUMERATE_SQL_TOKEN("MATERIALIZED", Materialized, Keyword)          \
    __ENUMERATE_SQL_TOKEN("NATURAL", Natural, Keyword)                    \
    __ENUMERATE_SQL_TOKEN("NO", No, Keyword)                              \
    __ENUMERATE_SQL_TOKEN("NOT", Not, Keyword)                            \
    __ENUMERATE_SQL_TOKEN("NOTHING", Nothing, Keyword)                    \
    __ENUMERATE_SQL_TOKEN("NOTNULL", Notnull, Keyword)                    \
    __ENUMERATE_SQL_TOKEN("NULL", Null, Keyword)                          \
    __ENUMERATE_SQL_TOKEN("NULLS", Nulls, Keyword)                        \
    __ENUMERATE_SQL_TOKEN("OF", Of, Keyword)                              \
    __ENUMERATE_SQL_TOKEN("OFFSET", Offset, Keyword)                      \
    __ENUMERATE_SQL_TOKEN("ON", On, Keyword)                              \
    __ENUMERATE_SQL_TOKEN("OR", Or, Keyword)                              \
    __ENUMERATE_SQL_TOKEN("ORDER", Order, Keyword)                        \
    __ENUMERATE_SQL_TOKEN("OTHERS", Others, Keyword)                      \
    __ENUMERATE_SQL_TOKEN("OUTER", Outer, Keyword)                        \
    __ENUMERATE_SQL_TOKEN("OVER", Over, Keyword)                          \
    __ENUMERATE_SQL_TOKEN("PARTITION", Partition, Keyword)                \
    __ENUMERATE_SQL_TOKEN("PLAN", Plan, Keyword)                          \
    __ENUMERATE_SQL_TOKEN("PRAGMA", Pragma, Keyword)                      \
    __ENUMERATE_SQL_TOKEN("PRECEDING", Preceding, Keyword)                \
    __ENUMERATE_SQL_TOKEN("PRIMARY", Primary, Keyword)                    \
    __ENUMERATE_SQL_TOKEN("QUERY", Query, Keyword)                        \
    __ENUMERATE_SQL_TOKEN("RAISE", Raise, Keyword)                        \
    __ENUMERATE_SQL_TOKEN("RANGE", Range, Keyword)                        \
    __ENUMERATE_SQL_TOKEN("RECURSIVE", Recursive, Keyword)                \
    __ENUMERATE_SQL_TOKEN("REFERENCES", References, Keyword)              \
    __ENUMERATE_SQL_TOKEN("REGEXP", Regexp, Keyword)                      \
    __ENUMERATE_SQL_TOKEN("REINDEX", Reindex, Keyword)                    \
    __ENUMERATE_SQL_TOKEN("RELEASE", Release, Keyword)                    \
    __ENUMERATE_SQL_TOKEN("RENAME", Rename, Keyword)                      \
    __ENUMERATE_SQL_TOKEN("REPLACE", Replace, Keyword)                    \
    __ENUMERATE_SQL_TOKEN("RESTRICT", Restrict, Keyword)                  \
    __ENUMERATE_SQL_TOKEN("RETURNING", Returning, Keyword)                \
    __ENUMERATE_SQL_TOKEN("RIGHT", Right, Keyword)                        \
    __ENUMERATE_SQL_TOKEN("ROLLBACK", Rollback, Keyword)                  \
    __ENUMERATE_SQL_TOKEN("ROW", Row, Keyword)                            \
    __ENUMERATE_SQL_TOKEN("ROWS", Rows, Keyword)                          \
    __ENUMERATE_SQL_TOKEN("SAVEPOINT", Savepoint, Keyword)                \
    __ENUMERATE_SQL_TOKEN("SELECT", Select, Keyword)                      \
    __ENUMERATE_SQL_TOKEN("SET", Set, Keyword)                            \
    __ENUMERATE_SQL_TOKEN("TABLE", Table, Keyword)                        \
    __ENUMERATE_SQL_TOKEN("TEMP", Temp, Keyword)                          \
    __ENUMERATE_SQL_TOKEN("TEMPORARY", Temporary, Keyword)                \
    __ENUMERATE_SQL_TOKEN("THEN", Then, Keyword)                          \
    __ENUMERATE_SQL_TOKEN("TIES", Ties, Keyword)                          \
    __ENUMERATE_SQL_TOKEN("TO", To, Keyword)                              \
    __ENUMERATE_SQL_TOKEN("TRANSACTION", Transaction, Keyword)            \
    __ENUMERATE_SQL_TOKEN("TRIGGER", Trigger, Keyword)                    \
    __ENUMERATE_SQL_TOKEN("UNBOUNDED", Unbounded, Keyword)                \
    __ENUMERATE_SQL_TOKEN("UNION", Union, Keyword)                        \
    __ENUMERATE_SQL_TOKEN("UNIQUE", Unique, Keyword)                      \
    __ENUMERATE_SQL_TOKEN("UPDATE", Update, Keyword)                      \
    __ENUMERATE_SQL_TOKEN("USING", Using, Keyword)                        \
    __ENUMERATE_SQL_TOKEN("VACUUM", Vacuum, Keyword)                      \
    __ENUMERATE_SQL_TOKEN("VALUES", Values, Keyword)                      \
    __ENUMERATE_SQL_TOKEN("VIEW", View, Keyword)                          \
    __ENUMERATE_SQL_TOKEN("VIRTUAL", Virtual, Keyword)                    \
    __ENUMERATE_SQL_TOKEN("WHEN", When, Keyword)                          \
    __ENUMERATE_SQL_TOKEN("WHERE", Where, Keyword)                        \
    __ENUMERATE_SQL_TOKEN("WINDOW", Window, Keyword)                      \
    __ENUMERATE_SQL_TOKEN("WITH", With, Keyword)                          \
    __ENUMERATE_SQL_TOKEN("WITHOUT", Without, Keyword)                    \
    __ENUMERATE_SQL_TOKEN("_identifier_", Identifier, Identifier)         \
    __ENUMERATE_SQL_TOKEN("_numeric_", NumericLiteral, Number)            \
    __ENUMERATE_SQL_TOKEN("_eof_", Eof, Invalid)                          \
    __ENUMERATE_SQL_TOKEN("_invalid_", Invalid, Invalid)                  \
    __ENUMERATE_SQL_TOKEN("&", Ampersand, Operator)                       \
    __ENUMERATE_SQL_TOKEN("*", Asterisk, Operator)                        \
    __ENUMERATE_SQL_TOKEN(",", Comma, Punctuation)                        \
    __ENUMERATE_SQL_TOKEN("/", Divide, Operator)                          \
    __ENUMERATE_SQL_TOKEN("||", DoublePipe, Operator)                     \
    __ENUMERATE_SQL_TOKEN("=", Equals, Operator)                          \
    __ENUMERATE_SQL_TOKEN("==", EqualsEquals, Operator)                   \
    __ENUMERATE_SQL_TOKEN(">", GreaterThan, Operator)                     \
    __ENUMERATE_SQL_TOKEN(">=", GreaterThanEquals, Operator)              \
    __ENUMERATE_SQL_TOKEN("<", LessThan, Operator)                        \
    __ENUMERATE_SQL_TOKEN("<=", LessThanEquals, Operator)                 \
    __ENUMERATE_SQL_TOKEN("-", Minus, Operator)                           \
    __ENUMERATE_SQL_TOKEN("%", Modulus, Operator)                         \
    __ENUMERATE_SQL_TOKEN("!=", NotEquals1, Operator)                     \
    __ENUMERATE_SQL_TOKEN("<>", NotEquals2, Operator)                     \
    __ENUMERATE_SQL_TOKEN(")", ParenClose, Punctuation)                   \
    __ENUMERATE_SQL_TOKEN("(", ParenOpen, Punctuation)                    \
    __ENUMERATE_SQL_TOKEN(".", Period, Operator)                          \
    __ENUMERATE_SQL_TOKEN("|", Pipe, Operator)                            \
    __ENUMERATE_SQL_TOKEN("+", Plus, Operator)                            \
    __ENUMERATE_SQL_TOKEN(";", SemiColon, Punctuation)                    \
    __ENUMERATE_SQL_TOKEN("<<", ShiftLeft, Operator)                      \
    __ENUMERATE_SQL_TOKEN(">>", ShiftRight, Operator)                     \
    __ENUMERATE_SQL_TOKEN("~", Tilde, Operator)

enum class TokenType {
#define __ENUMERATE_SQL_TOKEN(value, type, category) type,
    ENUMERATE_SQL_TOKENS
#undef __ENUMERATE_SQL_TOKEN
        _COUNT_OF_TOKENS,
};

enum class TokenCategory {
    Invalid,
    Keyword,
    Identifier,
    Number,
    Operator,
    Punctuation,
};

class Token {
public:
    Token(TokenType type, StringView value, size_t line_number, size_t line_column)
        : m_type(type)
        , m_value(value)
        , m_line_number(line_number)
        , m_line_column(line_column)
    {
    }

    static StringView name(TokenType);
    static TokenCategory category(TokenType);

    StringView name() const { return name(m_type); }
    TokenType type() const { return m_type; }
    TokenCategory category() const { return category(m_type); }

    StringView value() const { return m_value; }
    double double_value() const;

    size_t line_number() const { return m_line_number; }
    size_t line_column() const { return m_line_column; }

private:
    TokenType m_type;
    StringView m_value;
    size_t m_line_number;
    size_t m_line_column;
};

}
