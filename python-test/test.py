from selenium import webdriver
from selenium.webdriver.common.keys import Keys

driver = webdriver.Firefox()
driver.get("https://10.130.53.198")
assert "IPM Infrastructure" in driver.title
elem = driver.find_element_by_id ("login-input-username")
elem.clear()
elem.send_keys("admin")
elem = driver.find_element_by_id ("login-input-password")
elem.clear()
elem.send_keys("nosoup4u!")
elem.send_keys(Keys.RETURN)
assert "No results found." not in driver.page_source
driver.close()
