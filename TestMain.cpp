#include <UnitTest++\UnitTest++.h>

/**
 * @class Book
 * @brief Represent book
 */
class Book
  {
  public:
    Book();
    /// Get number of read pages of book
    int GetNumberOfReadPages() const;
    /*
     * @param i_number_of_pages number of pages, which will be add
     */
    void AddReadPages(int i_number_of_pages);
  private:
    bool _CheckPagesParams(int i_number_of_pages);

    int m_number_of_read_pages;
  };

int main()
  {
  UnitTest::RunAllTests();
  return 0;;
  }

Book::Book() : m_number_of_read_pages(0)
  {
  }

int Book::GetNumberOfReadPages() const
  {
  return m_number_of_read_pages;
  }

void Book::AddReadPages(int i_number_of_pages)
  {
  if (_CheckPagesParams(i_number_of_pages))
    return;
  m_number_of_read_pages += i_number_of_pages;
  }

bool Book::_CheckPagesParams(int i_number_of_pages)
  {
  return i_number_of_pages >= 0;
  }

SUITE(Book)
  {
  TEST(AddReadPages)
    {
    Book book;
    book.AddReadPages(10);
    int expexted1 = 10;
    int actual1 = book.GetNumberOfReadPages();
    CHECK_EQUAL(expexted1, actual1);

    book.AddReadPages(40);
    int expexted2 = 50;
    int actual2 = book.GetNumberOfReadPages();
    CHECK_EQUAL(expexted2, actual2);
    }
  }