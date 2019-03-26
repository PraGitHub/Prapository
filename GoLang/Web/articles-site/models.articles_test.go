// models.article_test.go

package main

import "testing"

// Test the function that fetches all articles
func TestGetAllArticles(t *testing.T) {
	alist := getAllArticles()

	// Check that the length of the list of articles returned is the
	// same as the length of the global variable holding the list
	if len(alist) != len(articleList) {
		t.Fail()
	}

	// Check that each member is identical
	for i, v := range alist {
		if v.Content != articleList[i].Content ||
			v.ID != articleList[i].ID ||
			v.Title != articleList[i].Title {

			t.Fail()
			break
		}
	}
}

func TestGetArticleById(t *testing.T) {
	alist := getAllArticles()
	a := alist[0]
	found, aFromFunc := getArticleById(a.ID)
	if found {
		if a != aFromFunc {
			t.Fail()
		}
	} else {
		t.Fail()
	}
	found,aFromFunc = getArticleById("0")
	if(found){
		t.Fail()
	}
}
