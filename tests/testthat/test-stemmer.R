context("test all stemmers")

test_that("French - test simple words", {
  expect_equal(object = french_stemmer(words = c("tester", "testament", "chevaux", "aromatique", "personnel", "folle", "acheteuse")),
               expected = c("test", "testament", "cheval", "aromat", "personel", "fou", "acheter"))
})

test_that("French - test words with accents", {
  expect_equal(object = french_stemmer(words = c("complète", "caisière")),
               expected = c("complet", "caisier"))
})

test_that("German - test simple words", {
  expect_equal(object = french_stemmer(words = c("kinder")),
               expected = c("kind"))
})

test_that("Spanish - test simple words", {
  expect_equal(object = spanish_stemmer(words = c("perros")),
               expected = c("perr"))
})

test_that("Italian - test simple words", {
  expect_equal(object = italian_stemmer(c("arrivederci")),
               expected = c("arrivederc"))
})

test_that("Portuguese - test simple words", {
  expect_equal(object = portuguese_stemmer(c("adeus")),
               expected = c("adeu"))
})

test_that("Finnish - test simple words", {
  expect_equal(object = finnish_stemmer(c("taivas")),
               expected = c("taiva"))
})

test_that("test empty word", {
  expect_equal(object = french_stemmer(words = c("")),
               expected = c(""))
  expect_equal(object = french_stemmer(words = c("123")),
               expected = c("123"))
  expect_equal(object = german_stemmer(words = c("")),
               expected = c(""))
  expect_equal(object = spanish_stemmer(words = c("")),
               expected = c(""))
  expect_equal(object = italian_stemmer(words = c("")),
               expected = c(""))
  expect_equal(object = portuguese_stemmer(words = c("")),
               expected = c(""))
  expect_equal(object = finnish_stemmer(words = c("")),
               expected = c(""))
})
