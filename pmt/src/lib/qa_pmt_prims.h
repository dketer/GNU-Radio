/* -*- c++ -*- */
/*
 * Copyright 2006 Free Software Foundation, Inc.
 * 
 * This file is part of GNU Radio
 * 
 * GNU Radio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * GNU Radio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with GNU Radio; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */
#ifndef INCLUDED_QA_PMT_PRIMS_H
#define INCLUDED_QA_PMT_PRIMS_H

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestCase.h>

class qa_pmt_prims : public CppUnit::TestCase {

  CPPUNIT_TEST_SUITE(qa_pmt_prims);
  CPPUNIT_TEST(test_symbols);
  CPPUNIT_TEST(test_booleans);
  CPPUNIT_TEST(test_integers);
  CPPUNIT_TEST(test_reals);
  CPPUNIT_TEST(test_complexes);
  CPPUNIT_TEST(test_pairs);
  CPPUNIT_TEST(test_vectors);
  CPPUNIT_TEST(test_equivalence);
  CPPUNIT_TEST(test_misc);
  CPPUNIT_TEST(test_dict);
  CPPUNIT_TEST(test_any);
  CPPUNIT_TEST(test_io);
  CPPUNIT_TEST(test_lists);
  CPPUNIT_TEST(test_serialize);
  CPPUNIT_TEST_SUITE_END();

 private:
  void test_symbols();
  void test_booleans();
  void test_integers();
  void test_reals();
  void test_complexes();
  void test_pairs();
  void test_vectors();
  void test_equivalence();
  void test_misc();
  void test_dict();
  void test_any();
  void test_io();
  void test_lists();
  void test_serialize();
};

#endif /* INCLUDED_QA_PMT_PRIMS_H */

