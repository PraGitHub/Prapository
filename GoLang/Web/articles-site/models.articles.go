package main

type article struct {
	ID      string
	Author  string
	Title   string
	Genre   string
	Content string
}

// For this demo, we're storing the article list in memory
// In a real application, this list will most likely be fetched
// from a database or from static files
var articleList = []article{
	article{ID: "1", Author: "Prashanth_1", Title: "Article 1", Genre: "Politics", Content: "Article 1 body"},
	article{ID: "2", Author: "Prashanth_2", Title: "Article 2", Genre: "Tech", Content: "Article 2 body"},
	article{ID: "3", Author: "Prashanth_3", Title: "Article 4", Genre: "Movies", Content: "Article 3 body"},
	article{ID: "4", Author: "Prashanth_4", Title: "Article 4", Genre: "Philosophy", Content: "Article 4 body"},
}

// Return a list of all the articles
func getAllArticles() []article {
	return articleList
}

func getArticleById(id string) (found bool, retArticle article) {
	found = false
	for _, xArticle := range articleList {
		if xArticle.ID == id {
			found = true
			retArticle = xArticle
			return
		}
	}
	return found, article{"", "", "", "", ""}
}
