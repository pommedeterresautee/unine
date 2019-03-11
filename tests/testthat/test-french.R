context("test French stemmer")

test_that("test simple words", {
  expect_equal(object = french_stemmer(words = c("tester", "testament", "chevaux", "aromatique", "personnel", "folle")),
               expected = c("test", "testament", "cheval", "aromat", "personnel", "fou"))
})

test_that("test words with accents", {
  expect_equal(object = french_stemmer(words = c("complète", "caissière")),
               expected = c("complet", "caissier"))
})

test_that("test empty word", {
  expect_equal(object = french_stemmer(words = c("")),
               expected = c(""))
})
