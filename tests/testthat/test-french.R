context("test French stemmer")

test_that("test simple words", {
  expect_equal(object = french_stemmer(words = c("tester", "testament", "chevaux", "aromatique", "personnel", "folle", "acheteuse")),
               expected = c("test", "testament", "cheval", "aromat", "personel", "fou", "acheter"))
})

test_that("test words with accents", {
  expect_equal(object = french_stemmer(words = c("complète", "caisière")),
               expected = c("complet", "caisier"))
})

test_that("test empty word", {
  expect_equal(object = french_stemmer(words = c("")),
               expected = c(""))
})
